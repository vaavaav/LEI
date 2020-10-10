package Model;

import java.util.ArrayList;
import java.util.List;

class Contact {

    private List<String> info;

    /*  (Name, Information)
        Information:
            0 - Name
            1 - Cellphone
            2 - Telephone
            3 - Address
            4 - Skype
     */

    private static final int length = 5;

    Contact(Contact c){
        this.info = new ArrayList<>(c.getInfo());
    }

    Contact(List<String> info){
        this.info = new ArrayList<>(info);
    }

    public List<String> getInfo(){
        return new ArrayList<>(this.info);
    }

    public String getInfoNumber(int n){
        return this.info.get(n);
    }

    public void setInfoNumber(int n, String newInfo) {
        this.info.set(n, newInfo);
    }

    public Contact clone(){
        return new Contact(this.info);
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();

        sb.append("Name: "     ).append(this.info.get(0)).append("\n");
        sb.append("Cellphone: ").append(this.info.get(1)).append("\n");
        sb.append("Telephone: ").append(this.info.get(2)).append("\n");
        sb.append("Address: "  ).append(this.info.get(3)).append("\n");
        sb.append("Skype: "    ).append(this.info.get(4)).append("\n");

        return sb.toString();
    }
}
