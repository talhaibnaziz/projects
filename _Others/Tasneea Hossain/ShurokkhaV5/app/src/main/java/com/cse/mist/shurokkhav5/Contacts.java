package com.cse.mist.shurokkhav5;

/**
 * Created by TASNEEA on 9/24/2017.
 */

public class Contacts {
    String id;
    String name;
    String number;

    public Contacts() {

    }

    public Contacts(String id, String name, String number) {

        this.id = id;
        this.name = name;
        this.number = number;
    }

    public String getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getNumber() {
        return number;
    }
}
