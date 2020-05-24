

#ifndef _HASH_TABLE_
#define _HASH_TABLE_


template <typename HashObj>
class HashTable
{
public:
    explicit HashTable(int size = 101);
    bool contains(const HashObj &x) const;

    void makeEmpty();
    bool insert(const HashObj &x);
    bool insert(HashObj &&x);
    bool remove(const HashObj &x);

private:
    std::vector<list<HashObj>> theLists;
    int currentSize;
    void rehash();
    size_t myhash(const HashObj &x) const;
};

#endif
