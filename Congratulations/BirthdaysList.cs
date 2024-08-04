using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Congratulations
{
    public class BirthdaysList
    {
        List<Birthday> birthdays;
        int nextId = 1;
        public List<Birthday> Birthdays { get { return birthdays; } }

        public BirthdaysList() { birthdays = new List<Birthday>(); }

        public void AddBirthday(string name, string surname, int day, int month, int year) 
        {
            //TODO --- Изменить способ назначения индекса
            birthdays.Add(new Birthday(nextId++, name, surname, day, month, year));
        }
        public void RemoveBirthday(int id) 
        {
            Birthday? birthday = birthdays.FirstOrDefault(birthday => birthday.Id == id);
            if (birthday != null)
            {
                birthdays.Remove(birthday);
            }
        }
        public void ViewBirthdayList()
        {
            foreach (var birthday in birthdays)
            {
                Console.WriteLine(birthday.ToString());
            }
        }
        public void ViewNearestBirthdayList()
        {
            foreach(var birthday in birthdays)
            {
                if(birthday.ItsToday() || birthday.ItsTomorrow())
                    Console.WriteLine(birthday.ToString());
            }
        }
    }
}
