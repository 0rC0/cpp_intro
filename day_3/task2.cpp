#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cstdint>
// Tasks for the computer lab II
// A hospital asks you to implement a patient database and you have
// never heard of actual databases so you want to implement it in C++!
// You need to provide an interface that offers the following options:
// Add new patient record [a]
// Delete patient record by id [d]
// Print record by id [p]
// Quit [q]
// You expect the database to grow quickly so these operations should be
// as fast as possible.
// "Add..." should check if the record exists already and produce an
// A patient record consists of name, patient-id (0-1'000'000) and health-
// status ("healthy", "sick", "dead").

enum Health_status
{
  healthy, sick, dead
};

Health_status str2status(std::string const & s)
{
  while (true)
  {
    if (s=="healthy")
      return Health_status::healthy;
    else if (s=="sick")
      return Health_status::sick;
    else if (s=="dead")
      return Health_status::dead;
    else
      return Health_status::dead; //ToDo: ask to reenter the status
  }
}

std::string status2string(Health_status const & h)
{
  if (h == Health_status::healthy)
    return "healthy";
  else if (h == Health_status::sick)
    return "sick";
  else
    return "dead";
}

struct Record
{
  //uint32 id;
  std::string name;
  Health_status status;

  void print_record()
  {
    if (name != "")
    {
    std::cout << "Name: "
              << name
              << ", status: "
              <<  status2string(status)
              << "\n\n";
    }
    else
      std::cout << "Not Found \n\n";
  }
};

struct Db
{
  std::unordered_map<uint32_t, Record> entries{};
  uint32_t last_id{0};

  void add(Record const & r)
  {
    uint32_t new_id = last_id + 1;
    entries[new_id] = r;
  }

  void search(uint32_t const id)
  {
    std::cout << "Id: " << id << '\n';
    entries[id].print_record();
  }

  void del(uint32_t const id)
  {
    entries.erase(id);
  }
};

int  main()
{
  Db database;
  while (true)
  {
    char action{};
    std::cout << "Add new patient record [a] \n"
              << "Delete patient record by id [d] \n"
              << "Print record by id [p]\n"
              << "Quit [q]\n";
    std::cin >> action;
    if (action=='q')
      break;
    else if (action=='a')
    {
        std::cout << "Insert Patient name and status\n";
        Record new_record;
        std::string status_string;
        std::cin >> new_record.name >> status_string;
        new_record.status = str2status(status_string);
        database.add(new_record);
    }
    else if (action=='p')
    {
      uint32_t id;
      std::cout << "Insert record by id: \n";
      std::cin >> id;
      database.search(id);
    }
    else if (action=='d')
    {
      uint32_t id;
      std::cout << "Insert the ID to delete \n";
      std::cin >> id;
      database.del(id);
    }
    else
      continue;
  }
}
