using Congratulations.Entities;

namespace Congratulations.BirthdaysLogic
{
    public static class BirthdayExtension
    {
        /// <summary>
        /// Get count days before birthday
        /// </summary>
        /// <param name="birthday"></param>
        /// <returns></returns>
        public static int DaysBeforeBirthday(this Birthday birthday)
        {
            return (new DateTime(DateTime.Today.Year, birthday.Date.Month, birthday.Date.Day) - DateTime.Today).Days;
        }
    }
}
