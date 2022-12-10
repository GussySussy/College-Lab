import java.io.*;
import java.util.Scanner;

public class File_Handling {
    public static void buffReader() throws IOException{
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            System.out.println("Enter something : ");
            String name = reader.readLine();
            System.out.println(name);
        } catch (IOException e) {
            System.out.println("I can't do this anymore.");
        }
    }

    public static void scannerClass() throws IOException{
        Scanner sc = new Scanner(System.in);
        try {
            System.out.println("Enter something : ");
            String something = sc.nextLine();
            System.out.println(something);
        } catch (IOError e) {
            System.out.println("I can't do this anymore.");
        }
        sc.close();
    }

    public static void fileOpIpStream() throws IOException{
        try{
            String s1 = "lezz fricken go guys";
        FileOutputStream fout = new FileOutputStream("sample.txt");
        char ch[] = s1.toCharArray();
        for(int i=0;i<s1.length();i++){
            fout.write(ch[i]);
        }
        fout.flush();
        fout.close();
        FileInputStream in = new FileInputStream("sample.txt");
        int i = 0;
        while((i=in.read())!=-1){
            System.out.print((char)i);
        }
        in.close();
        }
        catch(IOException e){
            System.out.println("IO exception.");
        }
        
    }

    public static void fileWriterReader() throws IOException{
        try{
            FileWriter writer = new FileWriter("sample2.txt");
            writer.write("I just wanna die");
            writer.close();
            System.out.println("\n\nSuccessfully wrote to file.\n");
        }
        catch(IOException e){
            System.out.println("Caught an IOException. ACHOOO!");
            e.printStackTrace();
        }
        try{
            FileReader reader = new FileReader("sample2.txt");
            int i=0;
            while((i=reader.read())!=-1){
                System.out.print((char)i);
            }
            reader.close();
            System.out.println("\n\nSuccessfully read the file.");
        }
        catch(IOException e){
            System.out.println("Caught an IOException. ACHOOO!");
            e.printStackTrace();
        }
    }

    public static void main(String[] args) throws IOException{
        buffReader();
        scannerClass();
        fileOpIpStream();
        fileWriterReader();
    }
}
