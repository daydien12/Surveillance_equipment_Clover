
#include "ringbuffer.h"

static void ringbuffer_increase_head(_ringbuffer_t *_rb_type_t_);
static void ringbuffer_increase_tail(_ringbuffer_t *_rb_type_t_);
static _rb_status_ ringbuffer_full(_ringbuffer_t *_rb_type_t_);
static _rb_status_ ringbuffer_empty(_ringbuffer_t *_rb_type_t_);
_rb_status_ ringbuffer_init(_ringbuffer_t *_rb_type_t_, unsigned char *arr_buffer, unsigned int size)
{
    if((size <= 0))
    {
        return Ringbuffer_Error;
    }
    else
    {
        _rb_type_t_->head          = 0;
        _rb_type_t_->tail          = 0;
        _rb_type_t_->data          = arr_buffer;
        _rb_type_t_->buffer_length = size+1;
    }
    return Ringbuffer_OK;
}

_rb_status_ ringbuffer_push(_ringbuffer_t *_rb_type_t_, unsigned char data)
{
    
    if((Ringbuffer_Full == ringbuffer_full(_rb_type_t_)))
    {
        ringbuffer_increase_tail(_rb_type_t_);
    }
    _rb_type_t_->data[_rb_type_t_->head] = data;
    ringbuffer_increase_head(_rb_type_t_);
    return Ringbuffer_push_done;
}

_rb_status_ ringbuffer_pop(_ringbuffer_t *_rb_type_t_, unsigned char *data)
{
    if(Ringbuffer_empty == ringbuffer_empty(_rb_type_t_))
    {
        return Ringbuffer_Error;
    }
    else
    {
        *data = _rb_type_t_->data[_rb_type_t_->tail];
        ringbuffer_increase_tail(_rb_type_t_);
    }
    return Ringbuffer_pop_done;
}

_rb_status_ ringbuffer_full(_ringbuffer_t *_rb_type_t_)
{
    if((_rb_type_t_->tail) != ((_rb_type_t_->head + 1) % _rb_type_t_->buffer_length))
    {
        return Ringbuffer_Error;
    }
    return Ringbuffer_Full;
}

_rb_status_ ringbuffer_empty(_ringbuffer_t *_rb_type_t_)
{
    if((_rb_type_t_->head) != (_rb_type_t_->tail))
    {
        return Ringbuffer_Error;
    }
    return Ringbuffer_empty;
}

unsigned int ringbuffer_get_tail(_ringbuffer_t *_rb_type_t_)
{
    return _rb_type_t_->tail;
}
unsigned int ringbuffer_get_head(_ringbuffer_t *_rb_type_t_)
{
    return _rb_type_t_->head;
}

static void ringbuffer_increase_head(_ringbuffer_t *_rb_type_t_)
{
     _rb_type_t_->head = ((_rb_type_t_->head + 1) % _rb_type_t_->buffer_length);
}

static void ringbuffer_increase_tail(_ringbuffer_t *_rb_type_t_)
{
    _rb_type_t_->tail = ((_rb_type_t_->tail + 1) % _rb_type_t_->buffer_length);
}