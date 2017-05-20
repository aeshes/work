#ifndef CARRAY_H
#define CARRAY_H

#include <string>
#include <exception>
#include <algorithm>


template <typename TData>
class CArray
{
public:
    typedef TData value_type;
    typedef size_t size_type;

    // ����������� �� ���������
    CArray();

    // ����������� �����������
    CArray(
        const CArray & _array
    );

    //����������
    ~CArray();

    // �������� ���������� �����
    CArray & operator=(
        CArray _other
    );

    // ����������� �����������
	CArray(
		CArray && _other
	) noexcept;

    // �������� ������������ ��� �����������
	CArray & operator=(
		CArray && _other
    ) noexcept;

    // ������� ������
    void swap(
        CArray & _other
    );

    // �������� ������� � �����
    void push_back(
        const TData & _value
    );

    // �������� ������� � ������ �� ��������� �������
    void insert(
        unsigned int _index,
        const TData & _value
    );

	// ������� ������� ������� �� ��������� �������
    void erase(
        unsigned int _index
    );

    // �������� ������
    void clear();

    // ������� �������� ������ �������
    unsigned int size() const;

    // ������� ������� �������
    unsigned int capacity() const;

    // �������� ���������� ��������� � �������
    bool empty() const;

    // �������� ��������������
    TData & operator[](
        unsigned int _index
    );

    // �������� �������������� ������������ �������
	const TData & operator[](
		unsigned int _index
    ) const;

	// �������� ������
    TData * begin();

    // �������� ������ ������������ �������
    const TData * begin() const;

    // �������� �����
    TData * end();

    // �������� ����� ������������ �������
    const TData * end() const;

protected:
    TData * elements;            // ������ ���������
    TData * first_free;          // ��������� �� ������ ��������� �������
    TData * cap;                 // ��������� �� ������ "�������" ����� ����� �������
    void free();                 // ������������ ��������
    void reallocate();           // ����������������� ������ ��� ���������� ������� �������
    void check_and_realloc();    // �������� ������������� ���������� ������� ������� � ����� reallocate()
    void check_index(            // �������� ������������ �������� �������
        unsigned int _index,
        const std::string & _msg
    );
};

template <typename TData>
CArray<TData>::CArray()
    : elements(nullptr), first_free(nullptr), cap(nullptr) {}

template <typename TData>
CArray<TData>::~CArray()
{
    clear();
    free();
}

template <typename TData>
CArray<TData>::CArray(
    const CArray & _array
    )
{
    elements = new TData[_array.capacity()];

    for (size_type i = 0; i < _array.size(); ++i)
        elements[i] = _array.elements[i];

    first_free = elements + _array.size();
    cap = elements + _array.capacity();
}

template <typename TData>
void CArray<TData>::swap(
    CArray & _other
    )
{
    using std::swap;
    swap(elements, _other.elements);
    swap(first_free, _other.first_free);
    swap(cap, _other.cap);
}

template <typename TData>
CArray<TData> & CArray<TData>::operator=(
    CArray _other
    )
{
    swap(_other);
    return *this;
}

template <typename TData>
CArray<TData>::CArray(
	CArray && _other
    ) noexcept : elements(_other.elements), first_free(_other.first_free), cap(_other.cap)
{
	_other.elements = _other.first_free = _other.cap = nullptr;
}

template <typename TData>
CArray<TData> & CArray<TData>::operator=(
    CArray && _other
    ) noexcept
{
	swap(_other);
	return *this;
}

template <typename TData>
void CArray<TData>::free()
{
    if (elements) delete[] elements;
    elements = first_free = cap = nullptr;
}

template <typename TData>
void CArray<TData>::reallocate()
{
    auto newcapacity = size() ? size() * 2 : 1;
    auto newdata = new TData[newcapacity];
    auto dest = newdata;
    auto elem = elements;

    for (size_type i = 0; i != size(); ++i)
        *dest++ = std::move(*elem++);
    free();

    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

template <typename TData>
void CArray<TData>::check_and_realloc()
{
    if (size() == capacity())
        reallocate();
}

template <typename TData>
void CArray<TData>::check_index(
    unsigned int _index,
    const std::string & _msg
    )
{
    if (_index >= size())
        throw std::out_of_range(_msg);
}

template <typename TData>
unsigned int CArray<TData>::size() const
{
    return first_free - elements;
}

template <typename TData>
unsigned int CArray<TData>::capacity() const
{
    return cap - elements;
}

template <typename TData>
bool CArray<TData>::empty() const
{
    return size() == 0;
}

template <typename TData>
void CArray<TData>::push_back(
    const TData & _value
    )
{
    check_and_realloc();
    *first_free++ = _value;
}

// �����������: ���������� ��������� ������� ������������ �������,
// ����� �� ��� �����, ����� ��������� �������. ��������� ������ �������
// � �� ������ �� ����������.
template <typename TData>
void CArray<TData>::insert(
    unsigned int _index,
    const TData & _value
    )
{
    check_index(_index, "CArray::insert: Index out of range");
    check_and_realloc();

    for (size_type i = size(); i > _index; --i)
        elements[i] = elements[i - 1];
    elements[_index] = _value;
    ++first_free;
}

template <typename TData>
void CArray<TData>::erase(
    unsigned int _index
    )
{
    if (size() == 1)
    {
        clear();
    }
    else
    {
        for (size_type i = _index + 1; i < size() - 1; ++i)
            elements[i - 1] = elements[i];
        --first_free;
    }
}

template <typename TData>
void CArray<TData>::clear()
{
    for (auto it = begin(); it != end(); ++it)
        it->TData::~TData();
    first_free = elements;
}

template <typename TData>
TData & CArray<TData>::operator[](
    unsigned int _index
    )
{
    check_index(_index, "CArray::operator[]: Index out of range");
    return elements[_index];
}

template <typename TData>
const TData & CArray<TData>::operator[](
        unsigned int _index
    ) const
{
	check_index(_index, "CArray::operator[] const: Index out of range");
	return elements[_index];
}

template <typename TData>
TData * CArray<TData>::begin()
{
    return elements;
}

template <typename TData>
const TData * CArray<TData>::begin() const
{
    return elements;
}

template <typename TData>
TData * CArray<TData>::end()
{
    return first_free;
}

template <typename TData>
const TData * CArray<TData>::end() const
{
    return first_free;
}

#endif