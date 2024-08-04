using System.ComponentModel.DataAnnotations;
using System.ComponentModel.DataAnnotations.Schema;

namespace Congratulations.Entities
{
    public class Person
    {
        public Guid Id { get; set; } = new Guid();
    [Required]
        public string? Name { get; set; }
        public int Age { get; set; }
        public string? Description { get; set; }
        public Birthday? Birthday { get; set; }
    }
}