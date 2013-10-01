#ifndef SHARED_CONTAINER_SIG_H
#define SHARED_CONTAINER_SIG_H

#include <mutex>
#include <boost/signals2.hpp>

namespace sj
{

template <typename T>
class shared_container_sig
{
public:
  class readonly_access
  {
  public:
    explicit readonly_access(shared_container& parent)
      : object(parent._object)
      , _parent(parent)
    {
      parent._lock.lock();
    }
    ~readonly_access() { _parent._lock.unlock(); }
    readonly_access(readonly_access&) = delete;
    void operator=(readonly_access&) =delete;

    const T& object;
  private:
    shared_container& _parent;
  };

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
      _parent._changed();
      _parent._lock.unlock();
    }
    transaction(transaction&) = delete;
    void operator=(transaction&) =delete;

    T& object;
  private:
    shared_container& _parent;
  };

  template <typename Slot>
  void connect(const Slot& slot) { _changed.connect(slot); }

private:
  boost::signals2::signal<void()> _changed;
  T _object;
  std::mutex _lock;
};

} // namespace sj

#endif // SHARED_CONTAINER_H
