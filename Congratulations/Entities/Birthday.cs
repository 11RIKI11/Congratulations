using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Congratulations.Entities
{
    public class Birthday
    {
        public Guid Id { get; set; } = new Guid();
        public DateTime Date { get; set; }
        public Guid PersonId { get; set; }
        [Required]
        public Person Person { get; set; } = null!;
        public override string ToString()
        {
            return $"{Person.Name}, {Person.Age} -> {Date.Year:0000}:{Date.Month:00}:{Date.Day:00}. {Person.Description}";
        }
    }
}