#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_V 26

int main() {
    int N;
    scanf("%d", &N);

    for (int case_num = 1; case_num <= N; case_num++) {
        int V, E;
        scanf("%d %d", &V, &E);

        int adj[MAX_V][MAX_V] = {0};

        for (int i = 0; i < E; i++) {
            char u_char, v_char;
            scanf(" %c %c", &u_char, &v_char);
            int u = u_char - 'a';
            int v = v_char - 'a';
            adj[u][v] = 1;
            adj[v][u] = 1;
        }

        bool visited[MAX_V] = {false};
        char components[MAX_V][MAX_V];
        int component_sizes[MAX_V] = {0};
        int num_components = 0;

        for (int node = 0; node < V; node++) {
            if (!visited[node]) {
                int queue[MAX_V];
                int front = 0, rear = 0;
                queue[rear++] = node;
                visited[node] = true;

                int component[MAX_V];
                int comp_size = 0;
                component[comp_size++] = node;

                while (front < rear) {
                    int current = queue[front++];
                    for (int neighbor = 0; neighbor < V; neighbor++) {
                        if (adj[current][neighbor] && !visited[neighbor]) {
                            visited[neighbor] = true;
                            queue[rear++] = neighbor;
                            component[comp_size++] = neighbor;
                        }
                    }
                }

                for (int i = 0; i < comp_size - 1; i++) {
                    for (int j = i + 1; j < comp_size; j++) {
                        if (component[i] > component[j]) {
                            int temp = component[i];
                            component[i] = component[j];
                            component[j] = temp;
                        }
                    }
                }

                for (int i = 0; i < comp_size; i++) {
                    components[num_components][i] = component[i] + 'a';
                }
                component_sizes[num_components] = comp_size;
                num_components++;
            }
        }

        for (int i = 0; i < num_components - 1; i++) {
            for (int j = 0; j < num_components - i - 1; j++) {
                if (components[j][0] > components[j + 1][0]) {
                    char temp_component[MAX_V];
                    int temp_size = component_sizes[j];
                    memcpy(temp_component, components[j], temp_size);
                    memcpy(components[j], components[j + 1], component_sizes[j + 1]);
                    component_sizes[j] = component_sizes[j + 1];
                    memcpy(components[j + 1], temp_component, temp_size);
                    component_sizes[j + 1] = temp_size;
                }
            }
        }

        printf("Case #%d:\n", case_num);
        for (int i = 0; i < num_components; i++) {
            for (int j = 0; j < component_sizes[i]; j++) {
                printf("%c,", components[i][j]);
            }
            printf("\n");
        }
        printf("%d connected components\n\n", num_components);
    }

    return 0;
}
