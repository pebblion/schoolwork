package HotelProject;

import java.util.ArrayList;

public class HotelProject {
    
    public static void main(String[] args)
    {
        ArrayList<Hotel> hotels = new ArrayList<>();

        Hotel h1 = new Hotel("Hilton", 5);
        h1.setRating(4.1);

        h1.addRoom(new SingleRoom(101, 120.49, "Queen", true));
        h1.addRoom(new SingleRoom(102, 180.95, "King", true));
        h1.addRoom(new SingleRoom(203, 160.0, "Twin", false));
        h1.addRoom(new Suite(601, 402.49, 2, false));
        h1.addRoom(new Suite(602, 600.49, 3, true));

        Hotel h2 = new Hotel("Marriott", 4);
        h2.setRating(4.5);

        h2.addRoom(new SingleRoom(1001, 350, "Queen", false));
        h2.addRoom(new SingleRoom(1002, 377, "King", true));
        h2.addRoom(new Suite(1351, 1001, 2, true));
        h2.addRoom(new Suite(2362, 1500, 4, true));

        Hotel h3 = new Hotel("Wyndham", 5);
        h3.setRating(4.2);

        h3.addRoom(new SingleRoom(101, 120.49, "Twin", true));
        h3.addRoom(new SingleRoom(212, 180.95, "King", false));
        h3.addRoom(new SingleRoom(304, 160.0, "Twin", false));
        h3.addRoom(new Suite(504, 402.49, 4, true));
        h3.addRoom(new Suite(802, 600.49, 3, true));


        hotels.add(h1);
        hotels.add(h2);
        hotels.add(h3);
        Collections.sort(hotels);

        System.out.println("------------------------------------------------------------");
        for(Hotel h: hotels)
        {
            h.printInfo();
            System.out.println("------------------------------------------------------------");
            h.listRooms();
            System.out.println("------------------------------------------------------------");
        }

    }
}
