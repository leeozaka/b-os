import java.io.IOException;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String args[]) throws IOException {

        class DDD {
            public int DDD_num;
            public String destination;

        }

        class BancDDD extends DDD {
            private List<DDD> bd_ddd;

            public BancDDD() {
                bd_ddd = new ArrayList<>();
            }

            public void insereDDD(int DDD, String location) {
                DDD aux = new DDD();
                aux.DDD_num = DDD;
                aux.destination = location;
                bd_ddd.add(aux);
            }

            public DDD consulta(int consulta) {
                for (int i = 0; i < bd_ddd.size(); i++) {
                    if (bd_ddd.get(i).DDD_num == consulta) {
                        return bd_ddd.get(i);
                    }
                }
                return null;
            }
        }

        try (Scanner scan = new Scanner(System.in)) {
            int DDD_input = Integer.parseInt(scan.nextLine());

            BancDDD bd = new BancDDD();

            bd.insereDDD(61, "Brasilia");
            bd.insereDDD(71, "Salvador");
            bd.insereDDD(11, "Sao Paulo");
            bd.insereDDD(21, "Rio de Janeiro");
            bd.insereDDD(32, "Juiz de fora");
            bd.insereDDD(19, "Campinas");
            bd.insereDDD(27, "Vitoria");
            bd.insereDDD(31, "Belo Horizonte");

            DDD res = new DDD();

            try {
                res = bd.consulta(DDD_input);
                System.out.println(res.destination);
            } catch (Exception e) {
            }

        } catch (NumberFormatException e) {
            e.printStackTrace();
        }

    }
}
