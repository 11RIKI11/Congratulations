using Congratulations.DbContext;
using Congratulations.Entities;
using Microsoft.EntityFrameworkCore;

namespace Congratulations.BirthdaysLogic
{
    public class BirthdaysService
    {
        private readonly CongratulationsDbContext _db;

        public BirthdaysService(CongratulationsDbContext db)
        {
            _db = db;
            CheckTodayBirthdays();
        }

        public void AddBirthday(Birthday? birthday)
        {
            if (birthday == null)
                return;

            birthday.Person.Age = DateTime.Today.Year - birthday.Date.Year - (birthday.DaysBeforeBirthday() <= 0 ? 0 : 1);
            _db.birthdays.Add(birthday);
            _db.SaveChanges();
        }

        public Birthday? RemoveBirthday(int index)
        {
            if (index >= _db.birthdays.Count())
                throw new IndexOutOfRangeException("День рождения с указанными номером не найден");
            Birthday birthday = _db.birthdays.ElementAt(index);
            if (birthday == null)
                return null;

            _db.persons.Remove(birthday.Person);
            _db.SaveChanges();
            return birthday;
        }

        public Birthday? EditBirthday(int index, Birthday? birthday)
        {
            if (index >= _db.birthdays.Count()) throw new IndexOutOfRangeException("День рождения с указанными номером не найден");
            Birthday? updateBirthday = _db.birthdays.Include(x => x.Person).ElementAt(index);

            if (updateBirthday == null)
                return null;

            updateBirthday.Date = birthday.Date;
            updateBirthday.Person.Name = birthday.Person.Name;
            updateBirthday.Person.Description = birthday.Person.Description;
            updateBirthday.Person.Age = DateTime.Today.Year - birthday.Date.Year - (birthday.DaysBeforeBirthday() <= 0 ? 0 : 1);

            _db.SaveChanges();
            return updateBirthday;
        }

        public List<Birthday> GetBirthday()
        {
            return _db.birthdays.Include(b => b.Person).ToList();
        }

        void CheckTodayBirthdays()
        {
            var birthdays = _db.birthdays.Include(b => b.Person).ToList();
            var todayBirthdays = birthdays.Where(b => b.DaysBeforeBirthday() == 0);

            foreach (var birthday in birthdays)
            {
                birthday.Person.Age = DateTime.Today.Year - birthday.Date.Year - (birthday.DaysBeforeBirthday() <= 0 ? 0 : 1);
                _db.Update(birthday);
            }
            _db.SaveChanges();
        }
    }
}
