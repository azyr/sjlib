#ifndef SHARED_CONTAINER_H
#define SHARED_CONTAINER_H

#include <mutex>

namespace sj
{

template <typename T>
class shared_container
{
public:
  class transaction
  {
  public:
    explicit transaction(shared_container& parent)
      : object(parent._object)
      , _parent(parent)
    {
      parent._lock.lock();
    }
    ~transaction()
    {
      _parent._lock.unlock();
    }
    transaction(transaction&) = delete;
    void operator=(transaction&) =delete;

    T& object;
  private:
    shared_container& _parent;
  };

private:
  T _object;
  std::mutex _lock;
};

} // namespace sj

#endif // SHARED_CONTAINER_H
