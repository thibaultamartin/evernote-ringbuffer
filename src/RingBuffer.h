#ifndef __evernote_ringbuffer__RingBuffer__
#define __evernote_ringbuffer__RingBuffer__

#include <cstddef>
#include <atomic>
#include <stdexcept>

template <typename T>
class RingBuffer {
    
private:
    T *m_buffer;
    const size_t m_size;
    size_t m_head;
    size_t m_tail;
    
    size_t next(size_t current) {
        return (current+1) % m_size;
    }
    
public:
    RingBuffer(size_t size) :
    m_size(size),
    m_head(0),
    m_tail(0) {
        m_buffer = new T[size];
    }
    
    virtual ~RingBuffer() {
        delete [] m_buffer;
    }
    
    void push(const T &object) {
        // Head is already placed at an "empty" space, storing object in buffer
        m_buffer[m_head] = object;
        
        // Positionning head at new "empty" place
        size_t next_head = next(m_head);
        m_head = next_head;
    }
    
    void pop() {
        // Nothing to do for deletion, just moving tail index
        // Positioning tail at "new" first element inserted and not deleted
        size_t next_tail = next(m_tail);
        m_tail = next_tail;
    }
    
    const T& operator[](size_t pos) {
        // No check on poss
        return m_buffer[pos];
    }
    
    const T& at(size_t pos) {
        // Checking if pos is within bounds
        if(pos >= m_size) {
            throw std::out_of_range("out of bounds");
        }
        
        return m_buffer[pos];
    }
};

#endif /* defined(__evernote_ringbuffer__RingBuffer__) */
