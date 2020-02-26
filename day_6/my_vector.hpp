#include <memory>

template <typename T>
class MyVector
{
private:
  size_t size{};
  std::unique_ptr<T[]> data{};
public:
  MyVector() = default;
  MyVector(MyVector const & rhs) { operator=(rhs); }
  MyVector(MyVector &&) = default;
  MyVector(size_t const s) : size{s}, data{new T[s]{}} {}
  MyVector & operator=(MyVector const & rhs)
  {
    if ( this != &rhs) {
      size = rhs.size;
      data.reset(new T[size]);
      for (size_t i = 0; i< size; ++i)
        data[i] = rhs.data[i];
    }
    return *this;
  }
  MyVector & operator=(MyVector && rhs) = default;
  ~MyVector() = default;

  MyVector & operator[](size_t n)
  {
    T out{};
    size_t c = 1;
    for (auto const i : data) {
      std::cout << i <<'\n';
      if (c==n) {
        out = i;
        break;
      }
      c += 1;
    }
    return out;
  }
  T* begin() {return data.get();}
  T* end() const { return data.get() + size;}

  size_t const & sizes()
  {
    return size;
  }

  void resize(size_t const & s)
  {
      T* old = data.get();
      size_t old_size = size;
      size = old_size + s;
      data.reset(new T[size]);
      for (size_t i = 0; i< old_size; ++i)
        data[i] = old[i];
      //inizialize new spaces to 0
      for (size_t i = old_size; i<size; ++i)
        data[i] = 0;
  }

  void push_back(T const & item)
  {
    this->resize(1);
    data[size-1] = item;
  }

};
