template <typename T>
class MyVector
{
private:
  T* data{};
  size_t size{};
public:
  MyVector() = default;
  MyVector(MyVector const & rhs) { operator=(rhs); }
  MyVector(MyVector &&) = default;
  MyVector & operator=(MyVector const & rhs)
  {
    if (this != &rhs) { // check self assignment
      size = rhs.size; // copy size
      delete[] data; data = new T[size]; //deallocate and reallocate
      for (size_t i = 0; i < size; ++i)
        data[i] = rhs.data[i]; // copy every element
    }
    return *this;
  }
  MyVector & operator=(MyVector && rhs)
  {
  size = rhs.size;
  delete[] data; data = rhs.data;
  rhs.data = nullptr;
  return *this;
  }
  
  MyVector & operator[](int const & j)
  {
    int n = 0;
    for (auto const d : data) {
      if (n == j) break;
      n += 1;
    
    return d;
    } 
  }
  
  MyVector(size_t const s) { size=s; data=new T[s]{}; }
  ~MyVector() { delete[] data; }
  
  T* begin() { return data; }
  T* end() { return data + size; }
  
  MyVector push_back(T item)
  { 
    T* old = data;
    delete[] data; data = new T[size+1];
    for (size_t i = 0; i < size + 1; ++i) {
      if (i==size+1)
        data[i] = item;
      else
        data[i] = old[i];
    }
  }

  
};