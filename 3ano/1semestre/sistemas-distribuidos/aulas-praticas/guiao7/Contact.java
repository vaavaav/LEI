import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOError;
import java.io.IOException;
import java.util.*;
import java.util.stream.Collectors;

public class Contact {
    private String name;
    private int age;
    private long phoneNumber;
    private String company;     // Pode ser null
    private List<String> emails;

    public Contact (String name, int age, long phone_number, String company, List<String> emails) {
        this.name = name;
        this.age = age;
        this.phoneNumber = phone_number;
        this.company = company;
        this.emails = new ArrayList<>(emails);
    }

    public String toString () {
        StringBuilder builder = new StringBuilder();
        builder.append(this.name).append(";");
        builder.append(this.age).append(";");
        builder.append(this.phoneNumber).append(";");
        builder.append(this.company).append(";");
        builder.append("{");
        for (String s : this.emails) {
            builder.append(s).append(";");
        }
        builder.append("}");
        return builder.toString();
    }
    
    public String getName(){
        return name;
    }

    public int getAge(){
        return age;
    }

    public long getPhoneNumber(){
        return phoneNumber;
    }

    public String getCompany(){
        return company;
    }

    public List<String> getEmails(){
        return emails.stream().collect(Collectors.toList());
    }

    public static Contact deserialize(DataInputStream input) throws IOException{
        String name = input.readUTF();

        int age = input.readInt();

        long phone_number = input.readLong();

        boolean hasCompany = input.readBoolean();
        String company = null;
        if(hasCompany)
            company = input.readUTF();
        
        int numberOfEmails = input.readInt();
        List<String> emails = new ArrayList<>();
        for(int i = 0; i < numberOfEmails; i++)
            emails.add(input.readUTF());

        return new Contact(name, age, phone_number, company, emails);
    }

    public void serialize(DataOutputStream out) throws IOException{        
        out.writeUTF(this.getName());
        out.writeInt(this.getAge());
        out.writeLong(this.getPhoneNumber());
        boolean hasCompany;
        
        out.writeBoolean(hasCompany = ((company = this.getCompany()) != null));
        if(hasCompany)
            out.writeUTF(company);
        
        int numberOfEmails;    
        out.writeInt(numberOfEmails = (emails = this.getEmails()).size());
        for(int i = 0; i < numberOfEmails; i++)
            out.writeUTF(emails.get(i));
        
        out.flush();
    }

}
