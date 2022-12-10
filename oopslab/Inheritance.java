public class Inheritance {

    abstract class polygon {
        void nos() {
        };
    }

    class Triangle extends polygon {
        void nos() {
            System.out.println("I have 3 sides.");
        }
    }

    class Rectangle extends polygon {
        void nos() {
            System.out.println("I have 4 sides.");
        }
    }

    class Pentagon extends polygon {
        void nos() {
            System.out.println("I have 5 sides.");
        }
    }

    static void abstractclass() {
        Inheritance inh = new Inheritance();
        Triangle t = inh.new Triangle();
        Rectangle r = inh.new Rectangle();
        Pentagon p = inh.new Pentagon();
        t.nos();
        r.nos();
        p.nos();
    }

    public class Employee {
        int age, salary;
        String name, dept, ph;

        Employee(String name, String department, String phonenumber, int age, int salary) {
            this.name = name;
            ph = phonenumber;
            dept = department;
            this.age = age;
            this.salary = salary;
        }

        void deets() {
            System.out.println(name);
            System.out.println(dept);
            System.out.println(age);
            System.out.println(ph);
            System.out.println(salary);
        }
    }

    static void Emp() {
        Inheritance inh = new Inheritance();
        Employee emp = inh.new Employee("Manoj", "Computer Science", "9633983368", 19, 90000);
        emp.deets();
    }

    public static void main(String[] args) {
        abstractclass();
        Emp();
    }
}
