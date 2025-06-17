#include "user.h"
#include <algorithm>

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}

/** 
 * STUDENT TODO:
 * The definitions for your custom operators and special member functions will go here!
 */
std::ostream& operator<<(std::ostream& os, const User& user) 
{
  os << "User(name=" << user._name << ", friends=[";
  for (size_t i = 0; i < user._size; i++) {
      os << user._friends[i];
      if (i < user._size - 1) os << ", ";  // 添加逗号分隔符
  }
  os << "])";
  return os;
}

User::~User()
{
  delete []_friends;
}

User::User(const User& user) 
    : _name(user._name),
      _size(user._size),
      _capacity(user._size > 0 ? user._capacity : 0),  // 关键修改
      _friends(nullptr)
{
    if (_capacity > 0) {
        _friends = new std::string[_capacity];
        for (size_t i = 0; i < _size; ++i) {
            _friends[i] = user._friends[i];
        }
    }
}

User& User::operator=(const User& user)
{
  if(this != &user){
    User tmp(user);
    std::swap(_name, tmp._name);
    std::swap(_friends, tmp._friends);
    std::swap(_size, tmp._size);
    std::swap(_capacity, tmp._capacity);
  }
  return *this;
}

User& User::operator+=(User& rhs)
{
  if (this == &rhs) return *this;  // 防止用户自己加自己
  add_friend(rhs._name);
  rhs.add_friend(_name);
  return *this;
}

bool User::operator<(const User& rhs) const
{
  return _name < rhs._name;
}
