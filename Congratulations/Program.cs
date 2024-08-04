using Congratulations.BirthdaysLogic;
using Congratulations.DbContext;
using Congratulations.Entities;

namespace Congratulations
{
    internal class Program
    {
        static void Main(string[] args)
        {
            HandleUserInput();
        }
        public static void PrintMenu()
        {
            Console.Clear();
            Console.WriteLine("Главное меню:");
            Console.WriteLine("1) Отобразить весь список дней рождения");
            Console.WriteLine("2) Отобразить список сегодняшних и ближайших дней рождения");
            Console.WriteLine("3) Добавить запись в список дней рождения");
            Console.WriteLine("4) Удалить запись из списка дней рождения");
            Console.WriteLine("5) Изменить запись в списке дней рождения");
            Console.WriteLine("0) Выход");
        }

        static void HandleUserInput()
        {
            InputManager inputManager = new();
            BirthdaysManager birthdayView = new BirthdaysManager(new BirthdaysService(new CongratulationsDbContext()));
            birthdayView.ViewBirthdaysNear();
            inputManager.PressAnyKey();
            do
            {
                PrintMenu();

                string? choice = inputManager.GetUserChoice();
                Console.Clear();

                switch (choice)
                {
                    case "1":
                        birthdayView.ViewBirthdaysAll(); 
                        break;
                    case "2":
                        birthdayView.ViewBirthdaysNear(); 
                        break;
                    case "3":
                        birthdayView.Add(inputManager.GetBirthdayInfo()); 
                        break;
                    case "4":
                        {
                            int number = inputManager.GetBirthdayNumber();
                            if (number > 0)
                                birthdayView.Remove(number - 1);
                        }
                        break;
                    case "5":
                        {
                            int number = inputManager.GetBirthdayNumber();
                            if (number > 0)
                                birthdayView.Edit(number - 1, inputManager.GetBirthdayInfo());
                        }
                        break;
                    case "0":
                        return;
                    default:
                        Console.WriteLine("Неизвестный пункт меню...");
                        break;
                }

                inputManager.PressAnyKey();
            }while (true);
        }
    }
}