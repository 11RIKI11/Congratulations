using System.Text.RegularExpressions;
using Congratulations.Entities;

namespace Congratulations
{
    internal class InputManager
    {
        public string? GetUserChoice()
        {
            Console.WriteLine("Выберите действие:");
            return Console.ReadLine();
        }
        public Birthday? GetBirthdayInfo()
        {
            Console.Clear();
            Console.WriteLine("Введите полное имя (Псевдоним):");
            string name = RepeatInput<string>(i =>
            !string.IsNullOrEmpty(i) && new Regex(@"^([A-Za-zА-Яа-я]+\s?[A-Za-zА-Яа-я]+)*$").IsMatch(i) ? i : null, i => false);
            
            Console.WriteLine("Введите дату рождения:");
            Console.WriteLine("Введите год:");
            int year = RepeatInput<int?>(i => 
                int.TryParse(i, out int year) && year >= 1900 && year <= 2100 ? year : null, i => false).Value;
           
            Console.WriteLine("Введите месяц:");
            int month = RepeatInput<int?>(i =>
                int.TryParse(i, out int month) && month >= 1 && month <= 12 ? month : null, i => false).Value;
            
            Console.WriteLine("Введите день:");
            int day =  RepeatInput<int?>(i => 
                int.TryParse(i, out day) && day >= 1 && day <= 31 ? day : null, i => false).Value;

            Console.WriteLine("Добавьте описание (Любимые подарки, увлечения и т.д.) (0 - Отсутствие описания)");
            string description = RepeatInput(i => 
            !string.IsNullOrEmpty(i) && new Regex(@"^((([A-Za-zА-Яа-я]+(,\s|\s)?[A-Za-zА-Яа-я]+)*)|0?)$").IsMatch(i) ? i : null, i => i == "0");

            return new Birthday 
            { 
                Date = new DateTime(year, month, day), 
                Person = new Person { Name = name, Description = description }
            };
        }
        private T RepeatInput<T>(Func<string, T?> parser, Predicate<T> predicate, string errorMessage = "Ошибка ввода")
        {
            do
            {
                string? userInput = Console.ReadLine();
                if (userInput != null)
                {
                    T? parseValue = parser(userInput);

                    if (parseValue != null && !predicate(parseValue))
                        return parseValue;
                    else if(predicate(parseValue))
                        return default;
                }
                Console.Clear();
                Console.WriteLine(errorMessage + "\nПовторите попытку");

            }while(true);
        }

        public int GetBirthdayNumber()
        {
            Console.WriteLine("Введите номер записи (0 - Отмена)");
            int? numb = RepeatInput<int?>(i =>
                int.TryParse(i, out int numb) ? numb : null, i => i <= 0);
            if (numb == null)
            {
                return 0;
            }
            return (int)numb;
        }
        public void PressAnyKey()
        {
            Console.WriteLine("Нажмите любую клавишу, чтобы продолжить...");
            Console.ReadKey();
        }
    }
}
