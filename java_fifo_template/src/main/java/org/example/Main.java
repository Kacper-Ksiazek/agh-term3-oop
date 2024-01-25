package org.example;

import org.example.FIFO.FQueue;
import org.example.FIFO.FifoException;
import org.example.Person.Gender;
import org.example.Person.Person;

// ⚠️ Komentarz:
// package org.example wynika z tego, że jako build tool używam Maven'a.

public class Main {

    public static void main(String[] args) throws FifoException {
        FQueue<Person> queue = new FQueue<Person>();

        System.out.println("-----------------");
        System.out.println("Dodajemy elementy do kolejki ");
        System.out.println("-----------------");

        queue.FQEnqueue(new Person("Kacper", 21, Gender.Male));
        queue.FQEnqueue(new Person("Alicja", 25, Gender.Female));
        queue.FQEnqueue(new Person("Bartosz", 30, Gender.Male));
        queue.FQEnqueue(new Person("Celina", 22, Gender.Female));
        queue.FQEnqueue(new Person("Dominik", 28, Gender.Male));

        queue.FQPrint(true);

        System.out.println("-----------------");
        System.out.println("Po kolei zdejmujemy elementy z kolejki ");
        System.out.println("-----------------");

        int i = 1;
        Person dequeuedPerson = null;
        while (!queue.FQEmpty()) {
            dequeuedPerson = queue.FQDequeue();
            System.out.println("Element zdjety jako "+ i++ + " to: " + dequeuedPerson.toString());
        }

        System.out.println();
        queue.FQPrint(true);

        System.out.println("-----------------");
        System.out.println("Testowanie metody FQClear");
        System.out.println("-----------------");

        queue.FQEnqueue(new Person("Eliza", 26, Gender.Female));
        queue.FQEnqueue(new Person("Filip", 32, Gender.Male));
        queue.FQEnqueue(new Person("Gabriela", 24, Gender.Female));

        queue.FQPrint("Przed wyczyszczeniem kolejki: ");

        queue.FQClear();

        queue.FQPrint("\nPo wyczyszczeniu kolejki: ");
    }
}