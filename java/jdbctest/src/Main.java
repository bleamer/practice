import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import com.mysql.jdbc.*;

public class Main {

    public static void main(String[] args) {
        System.out.println("Hello World!");

//        String dbUrl = "jdbc:mysql://127.0.0.1:3306/amelia";
        String dbUrl = "jdbc:mysql://127.0.0.1:3306/LocalDev";
        String user = "root";
        String password = "root";

//        DriverManager.registerDriver(new com.mysql.jdbc.Driver ());

        try {
            DriverManager.registerDriver(new com.mysql.jdbc.Driver ());
            Connection conn = DriverManager.getConnection(dbUrl,user,"");
            Statement mystmt = (Statement) conn.createStatement();
            ResultSet myRs =  mystmt.executeQuery("select * from empData");

            while (myRs.next()){
                System.out.println(myRs.getString("id")+","+myRs.getString("name")+","+myRs.getString("dept"));
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

    }
}
