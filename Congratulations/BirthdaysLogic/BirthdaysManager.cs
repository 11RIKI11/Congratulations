using Congratulations.Entities;
using Microsoft.EntityFrameworkCore;

namespace Congratulations.BirthdaysLogic
{
    public class BirthdaysManager
    {
        private readonly BirthdaysService _birthdayService;

        public BirthdaysManager(BirthdaysService birthdayService)
        {
            _birthdayService = birthdayService;
        }

        public void Add(Birthday birthday)
        {
            try
            {
                _birthdayService.AddBirthday(birthday);
                Console.WriteLine("День рождения успешно добавлен");
            }
            catch (Exception ex)
            {
                Console.WriteLine(ex.Message);
            }

        }

        public void ViewBirthdaysAll()
        {
            var birthdays = _birthdayService.GetBirthday();

            int numb = 1;
            if (birthdays.Count > 0)
                Console.WriteLine("Список дней рождения:");
            foreach (var birthday in birthdays)
            {
                Console.WriteLine($"{numb++}. " + birthday.ToString());
            }
        }

        public void ViewBirthdaysNear()
        {
            var birthdays = _birthdayService.GetBirthday().Where(b => b.DaysBeforeBirthday() >= 0 && b.DaysBeforeBirthday() <= 7).ToList();

            int numb = 1;
            if (birthdays.Count > 0)
                Console.WriteLine("Список сегодняшних и ближайших дней рождения:");
            foreach (var birthday in birthdays)
            {
                Console.WriteLine($"{numb++}. " + birthday.ToString());
            }
        }

        public void Remove(int index)
        {
            try
            {
                if (_birthdayService.RemoveBirthday(index) == null)
                {
                    Console.WriteLine("Ошибка");
                }
                Console.WriteLine("День рождения успешно удалён");
            }
            catch (IndexOutOfRangeException ex)
            {
                Console.WriteLine(ex.Message);
            }
            catch (NullReferenceException)
            {
                Console.WriteLine("День рождения не найден");
            }
            catch (Exception)
            {
                Console.WriteLine("Ошибка");
            }
        }

        public void Edit(int index, Birthday? birthday)
        {
            try
            {
                _birthdayService.EditBirthday(index, birthday);
                Console.WriteLine("День рождения успешно изменён");
            }
            catch (IndexOutOfRangeException ex)
            {
                Console.WriteLine(ex.Message);
            }
            catch (Exception ex)
            {
                Console.WriteLine("Ошибка: " + ex.Message);
            }
        }
    }
}
