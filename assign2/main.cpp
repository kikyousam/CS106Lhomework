/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_set>
#include <sstream>
#include <vector>

std::string kYourName = "ZhongShuai Qin"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::set<std::string> get_applicants(std::string filename) {
  // STUDENT TODO: Implement this function.
  std::set<std::string> res;
  std::ifstream ifs(filename);
  if(ifs.is_open())
  {
    std::string line;
    while(std::getline(ifs, line))
    {
      res.insert(line);
    }
  }
  return res;
}

bool isNameMatched(std::string name1, std::string name2) {
  auto getParts = [](const std::string& name) {
      std::vector<std::string> parts;
      std::istringstream iss(name);
      std::string part;
      while (iss >> part) parts.push_back(part);
      return parts;
  };
  
  auto parts1 = getParts(name1);
  auto parts2 = getParts(name2);
  
  if (parts1.empty() || parts2.empty()) return false;
  
  return parts1.front()[0] == parts2.front()[0] && 
         parts1.back()[0] == parts2.back()[0];
}

// bool isNameMatched(std::string name1, std::string name2)
// {
//   std::istringstream iss1(name1);
//   std::istringstream iss2(name2);
//   std::string first_name1, last_name1, first_name2, last_name2;
//   iss1 >> first_name1 >> last_name1;
//   iss2 >> first_name2 >> last_name2;
//   return first_name1[0] == first_name2[0] && last_name1[0] == last_name2[0];
// }

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::set<std::string>& students) {
  // STUDENT TODO: Implement this function.
  std::queue<const std::string*> q;
  for(const auto& student: students)
  {
    if(isNameMatched(name, student))
    {
      q.push(&student);
    }
  }
  return q;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  // STUDENT TODO: Implement this function.
  int size = matches.size();
  if(size != 0)
  {
    return *matches.front();
  }
  if (matches.empty()) {
    return "NO MATCHES FOUND.";
  } 
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
