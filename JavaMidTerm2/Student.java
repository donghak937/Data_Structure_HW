package JavaMidTerm2;
public class Student{
    private String name;
    private int age;

    public Student(String names, int ages){
        name = names;
        age = ages;
    }
    public Student(){
        name = null;
        age = -1;
    }

    public void printInfo(int a){
        System.out.println((a+1) + "번째 학생의 이름 : " + name + " 나이 : " + age);
    }
    
}