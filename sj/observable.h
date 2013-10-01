#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <boost/signals2.hpp>

namespace sj
{

// Wrapper to allow notification when an object is modified.
template <typename Type>
class observable
{
public:
    // Instantiate one of these to allow modification.
    // The observers will be notified when this is destroyed after the modification.
    class transaction
    {
    public:
        explicit transaction(observable& parent)
            : object(parent._object)
            , _parent(parent)
        {}
        ~transaction() { _parent._changed(); }
        transaction(transaction&) = delete;
        void operator=(transaction&) = delete;

        Type& object;
    private:
        observable& _parent;
    };

    // Connect an observer to this object.
    template <typename Slot>
    void connect(const Slot& slot) { _changed.connect(slot); }

    // Read-only access to the object.
    const Type& get() const { return _object; }

private:
    boost::signals2::signal<void()> _changed;
    Type _object;
};

} // namespace sj

#endif // OBSERVABLE_H
