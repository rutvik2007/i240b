#ifndef DLINK_SEQ_HH_
#define DLINK_SEQ_HH_

#include "seq.hh"

#include <cassert>
#include <cstddef>
#include <memory>
#include <utility>

template <typename E> class DLinkSeqConstIter;

/** Doubly Linked List implementation */

template <typename E>
class DLink {
public:
    E data;
    DLink *next, *prev;
    DLink(const E& linkdata, DLink *prevp, DLink* nextp) :
    data(linkdata), next(nextp), prev(prevp)
    {}
    DLink(DLink *prevp = nullptr, DLink* nextp = nullptr) :
        next(nextp),
        prev(prevp)
    {}
};

template <typename E>
class DLinkSeq : public Seq<E> {

    DLink<E> *head, *tail;
    int cnt;
    
    void init(){
        cnt = 0;
        head = new DLink<E>;
        head->next = tail = new DLink<E>(head, nullptr);
    }
    void removeall() { // Return link nodes to free store
        DLink<E> *curr;
        while (head != nullptr) {
            curr = head;
            head = head->next;
            delete curr;
        }
    }
    friend class DLinkSeqConstIter<E>;

    enum class Private { TAG };
public:

    /** Constructor */
    DLinkSeq(Private tag){   
         init();  
    }
    static SeqPtr<E> make(){
        return std::make_unique<DLinkSeq<E>>(Private::TAG);
    }

    ~DLinkSeq(){
        removeall();
    }

    void clear(){
        removeall();
        init();
    }

    void push(const E& item){
        DLink<E> *last = tail->prev;
        DLink<E> *add = new DLink<E>(item, last, tail);
        tail->prev = add;
        last->next = add;
        cnt++;
    }

    void unshift(const E& item){
        DLink<E> *first = head->next;
        DLink<E> *add = new DLink<E>(item, head, first);
        first->prev = add;
        head->next = add;
        cnt++;
    }

    E pop(){
        assert(tail->prev != head && "pop on empty doubly linked sequence");
        DLink<E> *last = tail->prev;
        E retdata = last->data;
        last->prev->next = tail;
        tail->prev = last->prev;
        delete last;
        cnt--;
        return retdata;
    }

    E shift(){
        assert(tail->prev != head && "shift on empty doubly linked sequence");
        DLink<E> *first = head->next;
        E retdata = first->data;
        head->next = first->next;
        first->next->prev = head;
        delete first;
        cnt--;
        return retdata;
    }
    
    int size() const { return cnt; }

    ConstIterPtr<E> cbegin() const{
        const DLinkSeq *constThis = static_cast<const DLinkSeq*>(this);
        return std::make_unique<DLinkSeqConstIter<E>>(constThis);
    }

    ConstIterPtr<E> cend() const{
        const DLinkSeq *constThis = static_cast<const DLinkSeq*>(this);
        return std::make_unique<DLinkSeqConstIter<E>>(constThis, false);
    }

    
};

template <typename E>
class DLinkSeqConstIter : public ConstIter<E>{
DLink<E>* curr;
const DLinkSeq<E>* const seq;
public:
    DLinkSeqConstIter(const DLinkSeq<E>* const seq, bool isHead = true)
     : seq(seq), 
    curr(isHead ? seq->head->next : seq->tail->prev){}
    
    virtual operator bool(){
        return (curr != seq->head && curr != seq->tail);
    }
    DLinkSeqConstIter& operator++() {
        curr = curr->next;
        return *this;
    }
    DLinkSeqConstIter& operator--(){
        curr = curr->prev;
        return *this;
    }
    const E& operator*() {
        return curr->data;
    }
    const E* operator->() {
        return &curr->data;
    }
};


#endif //ifndef DLINK_SEQ_HH_