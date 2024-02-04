import networkx as nx
import matplotlib.pyplot as plt

#pip install networkx
#pip install matplotlib

G = nx.Graph()

G.add_nodes_from([0,1, 2, 3, 4,5,6,7,8,9,10,11,12,13,14])
#0 entrada
#1-4 examinacion y limpieza = 2
#5- 8 consulta = 3
#9-12 areas especializadas = 4 / rayos x o pruebas de sangre
#13-14 cirujia = 5

#conexiones
G.add_edge(0, 1, weight=2)
G.add_edge(0, 2, weight=2)
G.add_edge(0, 3, weight=2)
G.add_edge(0, 4, weight=2)

G.add_edge(5, 1, weight=3)
G.add_edge(5, 2, weight=3)
G.add_edge(6, 2, weight=3)
G.add_edge(6, 3, weight=3)
G.add_edge(7, 3, weight=3)
G.add_edge(7, 4, weight=3)
G.add_edge(8, 4, weight=3)

G.add_edge(9,  5, weight=4)
G.add_edge(9,  6, weight=4)
G.add_edge(10, 6, weight=4)
G.add_edge(10, 7, weight=4)
G.add_edge(11, 7, weight=4)
G.add_edge(11, 8, weight=4)
G.add_edge(12, 8, weight=4)

G.add_edge(13, 9, weight=5)
G.add_edge(13, 10, weight=5)
G.add_edge(14, 11, weight=5)
G.add_edge(14, 12, weight=5)


pos = nx.spring_layout(G)  # Posicionamiento de nodos
nx.draw(G, pos, with_labels=True, font_weight='bold', node_size=700, node_color='skyblue', font_size=10)

labels = nx.get_edge_attributes(G, 'weight')
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)

#show grapfh
plt.show()
