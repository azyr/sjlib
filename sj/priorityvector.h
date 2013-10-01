#include <vector>
#include <algorithm>

namespace sj
{

template <typename P, typename V>
class priority_vector
{
public:
	typedef std::pair<P,V> pair;

	class iterator
	{
	public:
		iterator(const priority_vector<P,V>* parent, int pos)
			: _parent(parent)
			, _pos(pos)
		{}
		bool operator != (const iterator& other) const
		{
			return _pos != other._pos;
		}
		V operator*() const
		{
			return _parent->at(_pos);	
		}
		const iterator& operator++()
		{
			++_pos;
			return *this;
		}
		const iterator& operator--()
		{
			--_pos;
			return *this;
		}
	private:
		const priority_vector<P,V>* _parent;
		int _pos;
	};

    explicit priority_vector() = default;

	// copy constructor
	priority_vector(const priority_vector<P,V>& other)
	{
        copy_helper(other);
	}
	// move constructor
	priority_vector(priority_vector<P,V>&& other)
    {
        move_helper(std::forward(other));
	}
	// copy assignment
	priority_vector<P,V>& operator=(const priority_vector<P,V>& other)
	{
        copy_helper(other);
        return *this;
	}	
	// move assignment
	priority_vector<P,V>& operator=(priority_vector<P,V>&& other)
	{
        move_helper(other);
        return *this;
	}	

	// copy version of insert
    void insert(const P& priority, const V& value, bool autosort = true)
    {
        _data.push_back(pair(priority, value));

		// sort containers	
		if (autosort)
			sort();		
	}	
	// move version of insert
	
	V at(int idx) const
	{
		return _data[idx].second;
	}

	// sort according to the priority
	void sort()
	{
		std::sort(_data.begin(), _data.end(),
			[](const pair& a, const pair& b) 
			{ return a.first > b.first; });
	}

	// iterator access
	iterator begin() const
	{
		return iterator(this, 0);
	}
	iterator end() const
	{
		return iterator(this, _data.size());
	}	
	// constant iterator access


private:
    void copy_helper(const priority_vector<P,V>& other)
    {
        _data = other._data;
    }
    void move_helper(priority_vector<P,V>&& other)
    {
        _data = std::move(other._data);
    }

	std::vector<std::pair<P,V>> _data;
};



} // namespace sj
