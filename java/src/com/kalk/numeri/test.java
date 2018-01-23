package com.kalk.numeri;

public class test {
    public static void main(String[] args) {
        // Complessi esempi di utilizzo
        System.out.println("--------- Test numeri complessi ---------");
        Complex c1 = new Complex(3.0, 6.0);
        Complex c2 = new Complex(5.0, 3.0);
        Complex c3 = new Complex();
        System.out.println("Complesso A: " + c1.getString());
        System.out.println("Complesso B: " + c2.getString());
        c3 = c2.somma(c1);
        System.out.println("Somma: " + c3.getString());
        c3 = c2.sottrai(c1);
        System.out.println("Sottrazione: " + c3.getString());
        c3 = c2.moltiplica(c1);
        System.out.println("Moltiplicazione: " + c3.getString());
        c3 = c2.dividi(c1);
        System.out.println("Divisione: " + c3.getString());
        c3 = c2.conjugate();
        System.out.println("Coniugato: " + c3.getString());
        System.out.println("Norma: " + String.valueOf(c2.norm()));
        c3 = c2.inverse();
        System.out.println("Inverso: " + c3.getString());

        // Quaternioni esempi di utilizzo
        System.out.println("--------- Test numeri quaternioni ---------");
        Quaternion n1 = new Quaternion(3.0, 6.0, 5.0, 3.0);
        Quaternion n2 = new Quaternion(5.0, 3.0, 6.0, 6.7);
        Quaternion n3 = new Quaternion();
        System.out.println("Quaternione A: " + n1.getString());
        System.out.println("Quaternione B: " + n2.getString());
        n3 = n2.somma(n1);
        System.out.println("Somma: " + n3.getString());
        n3 = n2.sottrai(n1);
        System.out.println("Sottrazione: " + n3.getString());
        n3 = n2.moltiplica(n1);
        System.out.println("Moltiplicazione: " + n3.getString());
        n3 = n2.dividi(n1);
        System.out.println("Divisione: " + n3.getString());
        n3 = n2.conjugate();
        System.out.println("Coniugato: " + n3.getString());
        System.out.println("Norma:" + String.valueOf(n2.norm()));
        n3 = n2.inverse();
        System.out.println("Inverso: " + n3.getString());
    }
}
