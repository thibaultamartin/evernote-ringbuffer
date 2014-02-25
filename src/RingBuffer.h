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
    size_t m_back;
    size_t m_front;
    bool m_full;
    
    size_t next(size_t current) {
        return (current+1) % m_size;
    }
    
    size_t prev(size_t current) {
        return (current-1) % m_size;
    }
    
    size_t pos_in_buffer(size_t pos) {
        return (m_back+pos) % m_size;
    }
    
public:
    RingBuffer(size_t size) :
    m_size(size),
    m_back(0),
    m_front(0),
    m_full(false) {
        m_buffer = new T[size];
    }
    
    virtual ~RingBuffer() {
        delete [] m_buffer;
    }
    
    void push_front(const T &object) {
        // Head is already placed at an "empty" space, storing object in buffer
        m_buffer[m_front] = object;
        
        // Positionning head at new "empty" place
        m_front = next(m_front);
        
        // If just filled the buffer, notify it
        if(m_front == m_back) {
            m_full = true;
        } else if(m_full) {
            // If buffer was full, override previous values
            m_back = next(m_back);
        }
    }
    
    void pop_front() {
        if(m_full) {
            m_full = false;
            m_back = prev(m_back);
        }
        
        m_front = prev(m_front);
    }
    
    const T& operator[](size_t pos) {
        size_t real_pos = pos_in_buffer(pos);

        return m_buffer[real_pos];
    }
    
    const T& at(size_t pos) {
        // Checking if pos is within bounds
        if(pos >= m_size) {
            throw std::out_of_range("out of bounds");
        }
        size_t real_pos = pos_in_buffer(pos);
        return m_buffer[real_pos];
    }
};

#endif /* defined(__evernote_ringbuffer__RingBuffer__) */
