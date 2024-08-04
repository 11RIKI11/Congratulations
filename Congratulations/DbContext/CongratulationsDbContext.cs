using Congratulations.Entities;
using Microsoft.EntityFrameworkCore;

namespace Congratulations.DbContext
{
    public class CongratulationsDbContext : Microsoft.EntityFrameworkCore.DbContext
    {
        public DbSet<Birthday> birthdays => Set<Birthday>();
        public DbSet<Person> persons => Set<Person>();
        public CongratulationsDbContext() => Database.EnsureCreated();
        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            optionsBuilder.UseSqlServer(@"Server=(local);Database=congratulationsdb;TrustServerCertificate=True;User Id=User;Password=user;Trusted_Connection=True;");
        }
        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<Birthday>()
                .ToTable(t => t.HasCheckConstraint("ValidDate", "[date] BETWEEN '1900-01-01' AND '2100-12-31'"));
            modelBuilder.Entity<Person>()
                .ToTable(t => t.HasCheckConstraint("ValidAge", "[Age] > 0 AND [Age] < 125"));
        }
    }
}