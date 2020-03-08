#include <memory>
#include <exception>
template <typename T>
class MyVector
{
private:
  size_t _size{}, _capacity{};
  std::unique_ptr<T[]> _data{};

  void _expand(size_t new_cap)
  {
    std::unique_ptr<T[]> tmp(std::make_unique<T[]>(new_cap));
    for (size_t i = 0; i < _size; ++i)
      tmp[i] = std::move(_data[i]);
    _data = std::move(tmp);
    _capacity = new_cap;
  }

public:
  MyVector() = default;
  MyVector(MyVector const & rhs) { operator=(rhs); } //cpoy constructor
  MyVector(MyVector && rhs) {operator=(std::move(rhs));}
  MyVector(size_t const s) : _size{s}, _data{new T[s]{}} {}
  //copy assignment
  MyVector & operator=(MyVector const & rhs)
  {
    if ( this != &rhs) {
      _size = rhs._size; //copy size
      _capacity = rhs._capacity; //copy capacity
      _data.reset(new T[_size]); //deallocate and reallocate
      for (size_t i = 0; i< _size; ++i)
        _data[i] = rhs._data[i]; //copy every element
    }
    return *this;
  }
  //move assignment
  MyVector & operator=(MyVector && rhs)
  {
    _size = rhs._size; //copy size
    _capacity = rhs._capacity; //copy capacity
    _data = std::move(rhs._data); //copy every element
    return *this;
  }

  ~MyVector() = default;

  MyVector & operator[](size_t idx)
  {
    return _data[idx];
  }

  T* begin() {return _data.get();}
  T* end() const { return _data.get() + _size;}

  size_t const & get_size()
  {
    return _size;
  }

  void resize(size_t new_size)
  {
    if (new_size > _capacity)
      _expand(new_size);
    _size = new_size;
  }

  void push_back(T elem)
  {
    if (_size == _capacity)
    {
      if(_capacity)
        _expand(_capacity << 1);
      else
        _expand();
    }
    _data[_size++] = std::move(elem);
  }

  T at(size_t i)
  {
      if (i > _size)
        throw std::out_of_range{"out of range"};
      return _data[i];
  }

};
