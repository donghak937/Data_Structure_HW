package JavaMidTerm2;
import JavaMidTerm2.school.info;

class InvalidScore extends Exception {
    public InvalidScore(){
        super("score no good ");
    }
}

public class Person {
    private String name;
    private int age;

    public static int callCount = 0;

    public static void scoreCheck(int score) throws InvalidScore{
        if (score < 0 || score > 100) {
            throw new InvalidScore();
        }
    }

    public Person(){
        this.name = null;
        this.age = -1;
    }

    public Person(String name, int age){
        this.name = name;
        this.age = age;
    }

    public Person(String name){
        this.name = name;
        this.age = -1;
    }

    public void printInfo(){
        System.out.println(name);
        System.out.println(age);
        callCount++; // 계속 유지
    }

    public double getAverage(int[] arr){
        double total = 0;
        for(int i = 0; i < arr.length; i++){
            total += arr[i];
        }
        return total / (double)arr.length;
    }

    public int[] makeArray(int n){
        int[] a = new int[n];
        for(int i = 0; i < n; i ++){
            a[i] = i+1;
        }

        return a;
    }

    public static void main(String[] arg){

        info in = new info();
        in.printInfo();

        enum Day {MON, TUE, WED, THU, FRI, SAT, SUN}

        Day day = Day.MON;

        System.out.println(day.ordinal() + " " + day.toString());

        Student[] students = new Student[3];
        students[0] = new Student("Dongha", 24);
        students[1] = new Student("Bormi", 22);
        students[2] = new Student("Bloons", 20);

        for(int i = 0; i < 3; i++){
            students[i].printInfo(i);
        }

        int count = 0;
        int[][] a = new int[3][4];
        for(int i = 0 ; i < a.length; i++){
            for(int j = 0; j < a[i].length; j++){
                a[i][j] = count++;
            }
        }

        for(int i = 0 ; i < a.length; i++){
            for(int j = 0; j < a[i].length; j++){
                System.out.print("["+ a[i][j] + "] ");
            }
            System.out.println();
        }

        try{
        int v = 10 / 0;
        } catch(Exception e){
            System.out.println("Can not divide by 0");
        } finally {
            System.out.println("end");
        }
        int score = -100;
        try{
            scoreCheck(score);

        } catch(InvalidScore e){
            System.out.println("Can not divide by 0");
        } finally {
            System.out.println("end");
        }

    }

    
}
