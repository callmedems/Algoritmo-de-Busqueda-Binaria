#include <iostream>
#include <vector>
#include <algorithm> // para la búsqueda, en sort() y lower_bound()
#include <string>

using namespace std;

struct Empleado {
    string nombre;
    int edad;
    string hobby;
    string habilidades;

    //  comparación alfabética de los nombres de empleados en el vector
    // para la línea sort()
    bool operator<(const Empleado& otro) const {
        return nombre < otro.nombre;
    }

    // búsqueda binaria
    static Empleado* buscarEmpleado(vector<Empleado>& empleados, const string& nombreEmpleado) {
        Empleado empleadoBuscado = {nombreEmpleado, 0, "", ""}; // es un placeholder
        // este será el iterador para buscar en el vector
        auto buscador = lower_bound(empleados.begin(), empleados.end(), empleadoBuscado);
        if (buscador != empleados.end() && buscador->nombre == nombreEmpleado) {
            return &*buscador;
        } else {
            return nullptr;
        }
    }
};

int main() {
    // el vector dado
    vector<Empleado> empleados = { {"Alice", 25, "Leer, Correr", "C++"}, {"Bob", 30, "Programar, Música", "Java"}, {"Charlie", 22, "Videojuegos, Pintura", "Python"}, {"David", 28, "Fútbol, Viajar", "JavaScript"}, {"Eve", 35, "Cocina, Jardinería", "C#"}, {"Frank", 27, "Ciclismo, Lectura", "Ruby"}, {"Grace", 32, "Natación, Ajedrez", "Go"}, {"Hank", 24, "Esquí, Fotografía", "Swift"}, {"Ivy", 29, "Yoga, Teatro", "TypeScript"}, {"Jack", 31, "Escalar, Piano", "Kotlin"}, {"Kathy", 26, "Leer, Cocina", "PHP"}, {"Leo", 33, "Correr, Ciclismo", "Perl"}, {"Mona", 29, "Cine, Teatro", "Scala"}, {"Nina", 24, "Natación, Viajes", "Rust"}, {"Oscar", 28, "Videojuegos, Música", "Haskell"}, {"Paul", 30, "Fotografía, Esquí", "SQL"}, {"Quincy", 27, "Ajedrez, Jardinería", "HTML/CSS"}, {"Rachel", 31, "Escalar, Yoga", "SASS"}, {"Steve", 34, "Piano, Correr", "R"}, {"Tina", 23, "Cocina, Videojuegos", "Lua"}, {"Uma", 29, "Teatro, Pintura", "Elixir"}, {"Victor", 32, "Viajar, Escalar", "MATLAB"}, {"Wendy", 25, "Ciclismo, Leer", "Dart"}, {"Xander", 30, "Música, Fútbol", "VB.NET"}, {"Yara", 28, "Correr, Jardinería", "Shell Scripting"}, {"Zane", 26, "Fotografía, Cine", "Objective-C"}, {"Albert", 35, "Leer, Pintura", "Clojure"}, {"Brenda", 31, "Yoga, Natación", "Erlang"}, {"Calvin", 33, "Ajedrez, Videojuegos", "C"}, {"Diana", 29, "Escalar, Esquí", "Fortran"}, {"Eli", 24, "Teatro, Piano", "Julia"}, {"Fiona", 27, "Cocina, Viajar", "Racket"}, {"George", 28, "Natación, Música", "Tcl"}, {"Helen", 30, "Correr, Fotografía", "F#"}, {"Isaac", 32, "Escalar, Jardinería", "Groovy"}, {"Jenny", 26, "Pintura, Leer", "PowerShell"}, {"Kevin", 31, "Ciclismo, Yoga", "Lisp"}, {"Linda", 34, "Cine, Teatro", "Prolog"}, {"Mike", 28, "Ajedrez, Programar", "PostgreSQL"}, {"Nora", 27, "Esquí, Escalar", "SQLite"}, {"Owen", 29, "Leer, Piano", "Cassandra"}, {"Paula", 25, "Viajar, Correr", "MongoDB"}, {"Quentin", 33, "Fotografía, Cine", "Redis"}, {"Rita", 30, "Ciclismo, Videojuegos", "Memcached"}, {"Sam", 26, "Correr, Jardinería", "MySQL"}, {"Tracy", 32, "Teatro, Leer", "MariaDB"}, {"Ulysses", 28, "Programar, Natación", "Oracle"}, {"Vera", 29, "Yoga, Música", "SQL Server"}, {"Will", 31, "Esquí, Jardinería", "Firebase"}, {"Xena", 27, "Escalar, Cine", "Neo4j"}, {"Yuri", 35, "Leer, Programar", "GraphQL"}, {"Zara", 24, "Fotografía, Pintura", "Docker"}, {"Arthur", 30, "Cocina, Música", "Kubernetes"}, {"Bella", 26, "Videojuegos, Esquí", "Ansible"}, {"Cody", 28, "Piano, Yoga", "Terraform"}, {"Derek", 33, "Leer, Jardinería", "Chef"}, {"Eva", 31, "Ciclismo, Cine", "Puppet"}, {"Fred", 29, "Programar, Escalar", "Jenkins"}, {"Gina", 34, "Natación, Ajedrez", "Travis CI"}, {"Harry", 27, "Escalar, Música", "CircleCI"}, {"Irene", 25, "Videojuegos, Fotografía", "GitLab CI"}, {"Jacob", 32, "Cocina, Leer", "GitHub Actions"}, {"Kara", 29, "Yoga, Correr", "Azure DevOps"}, {"Louis", 31, "Ajedrez, Programar", "AWS"}, {"Molly", 28, "Escalar, Natación", "GCP"}, {"Nate", 26, "Ciclismo, Teatro", "Heroku"}, {"Olivia", 30, "Fotografía, Jardinería", "Lambda"}, {"Peter", 35, "Leer, Programar", "S3"}, {"Quinn", 24, "Pintura, Cine", "EC2"}, {"Rose", 27, "Cocina, Escalar", "CloudFormation"}, {"Sean", 29, "Videojuegos, Música", "Elastic Beanstalk"}, {"Tara", 33, "Teatro, Ajedrez", "Azure Functions"}, {"Uri", 31, "Natación, Jardinería", "Cloudflare"}, {"Vince", 28, "Leer, Escalar", "Fastly"}, {"Willa", 30, "Yoga, Cine", "Kong"}, {"Ximena", 27, "Correr, Pintura", "Nginx"}, {"Yusuf", 29, "Ciclismo, Jardinería", "HAProxy"}, {"Zoe", 26, "Natación, Fotografía", "Consul"}, {"Andre", 31, "Escalar, Ajedrez", "Vault"}, {"Beth", 28, "Leer, Videojuegos", "Prometheus"}, {"Chris", 35, "Correr, Música", "Grafana"}, {"Daisy", 24, "Natación, Escalar", "Kibana"}, {"Ethan", 27, "Fotografía, Ciclismo", "ElasticSearch"}, {"Faith", 29, "Teatro, Piano", "Logstash"}, {"Gabe", 30, "Cocina, Leer", "Fluentd"}, {"Hazel", 32, "Ajedrez, Jardinería", "Kafka"}, {"Ian", 28, "Correr, Yoga", "RabbitMQ"}, {"Judy", 26, "Videojuegos, Fotografía", "ActiveMQ"}, {"Karl", 34, "Ciclismo, Programar", "Kafka Streams"}, {"Lena", 29, "Escalar, Cine", "Spark Streaming"}, {"Mick", 31, "Leer, Música", "Flink"}, {"Nina", 27, "Pintura, Jardinería", "Samza"} };

    // se ordena el vector de empleados por nombre gracias al bool operator
    sort(empleados.begin(), empleados.end());


    cout << "¿Desea buscar un empleado?: ";
    string decision;
    cin >> decision;

    while(decision == "si"){
        cout << "\nIngrese el nombre del empleado: ";
        string nombreEmpleado;
        cin >> nombreEmpleado;

        // almacenamos el resultado de búsqueda en el puntero
        Empleado* empleadoEncontrado = Empleado::buscarEmpleado(empleados, nombreEmpleado);

        if (empleadoEncontrado != nullptr) {
            cout << "\nEmpleado encontrado.\n" << endl;
            cout << "Nombre: " << empleadoEncontrado->nombre << endl;
            cout << "Edad: " << empleadoEncontrado->edad << endl;
            cout << "Hobbies: " << empleadoEncontrado->hobby << endl;
            cout << "Habilidades Técnicas: " << empleadoEncontrado->habilidades << endl;
        } else {
            cout << "\nEmpleado no encontrado." << endl;
            // si el puntero es nulo, no se encontró un match en la búsqueda.
        }

            cout << "\n¿Desea buscar un empleado? ";
            cin >> decision;
    }

    return 0;
}