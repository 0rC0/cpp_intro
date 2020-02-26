template <typename T>
class MyVector
{
private:
  T * data{};
  size_t size{};
public:
  MyVector() = default;
  MyVector(MyVector const & rhs) { operator=(rhs); }
  MyVector(MyVector &&) = default;
  MyVector & operator=(MyVector const & rhs)
  {
    if ( this != &rhs) {
      size = rhs.size;
      delete[] data; data = new T[size];
      for (size_t i = 0; i< size; ++i)
        data[i] = rhs.data[i];
    }
    return *this;
  }
  MyVector & operator=(MyVector && rhs) = default;
  MyVector(size_t const s) { size=s; data=new T[s]{}; }
  ~MyVector() { delete[] data; }

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
  T* begin() { return data; }
  T* end() { return data + size; }

  size_t const & sizes()
  {
    return size;
  }

  void resize(size_t const & s)
  {
      T* old = data;
      size_t old_size = size;
      size = old_size + s;
      delete[] data; data = new T[size + s];
      for (size_t i = 0; i< old_size; ++i)
        data[i] = old[i];
  }

  void push_back(T const & item)
  {
    this->resize(1);
    data[size-1] = item;
  }

};
