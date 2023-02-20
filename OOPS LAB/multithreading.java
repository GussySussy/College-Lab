import java.util.*;

public class multithreading {

    class Account {
        double balance, wamt, damt;

        Account(double b) {
            this.balance = b;
        }

        public synchronized double withdraw() {
            Scanner sc = new Scanner(System.in);
            System.out.println("Withdrawal process has started...");
            System.out.print("Enter money to withdraw : ");
            wamt = sc.nextDouble();
            System.out.println("Balance before withdrawal : " + balance);
            if (balance < wamt) {
                try {
                    System.out.println("Insufficient balance, waiting for deposit...");
                    wait();
                } catch (Exception e) {
                    System.out.print("Insufficient funds in the account.");
                }
            }
            balance = balance - wamt;
            System.out.println("Balance after withdrawal :" + balance);
            return wamt;
        }

        public synchronized double deposit() {
            Scanner sc = new Scanner(System.in);
            System.out.println("Deposit process has started...");
            System.out.print("Enter money to deposit : ");
            damt = sc.nextDouble();
            balance = balance + damt;
            System.out.println("Balance after deposit :" + balance);
            this.notify();
            return damt;
        }
    }

    class Thread1 extends Thread {
        Account a;

        Thread1(Account a) {
            this.a = a;
            Thread t = new Thread(this);
            t.start();
        }

        public void run() {
            a.withdraw();
        }
    }

    class Thread2 extends Thread {
        Account a;

        Thread2(Account a) {
            this.a = a;
            Thread t = new Thread(this);
            t.start();
        }

        public void run() {
            a.deposit();
        }
    }

    public static void main(String[] args) {
        multithreading x = new multithreading();
        Account acc = x.new Account(1000);
        x.new Thread1(acc);
        x.new Thread2(acc);
    }
}
