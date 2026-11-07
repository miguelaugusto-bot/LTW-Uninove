# Roteiro — montar a topologia no Cisco Packet Tracer (Disciplina 3)

O Packet Tracer só salva arquivos `.pkt` pelo próprio programa, então este roteiro e os scripts da pasta `configs-packet-tracer/` deixam a montagem pronta para colar. Tempo estimado: 1h30.
Salve como `topologia.pkt`, exporte a imagem (File → Export → Picture ou Ctrl+Shift+P) e inclua os dois no GitHub.

## 1. Dispositivos (modelo representativo: 1 equipamento de cada tipo por andar)
| Dispositivo no PT | Modelo no Packet Tracer | Observação |
|---|---|---|
| ISP | Cloud-PT (ou Router 2911) | 200.10.10.2/30 default-gateway do FW-01 |
| FW-01 | Router ISR4331 | Gi0/0/0 → ISP · Gi0/0/1 → SW-CORE-01 Fa0/1 |
| SW-CORE-01 | Switch 2960-24TT | Fa0/1 FW · Fa0/2–9 uplinks · Fa0/10–11 servidores |
| SW-TER-01 / SW-TER-02 | Switch 2960-24TT ×2 | Fa0/24 de cada um → SW-CORE-01 (Fa0/2/Fa0/3) |
| SW-P01-01 / SW-P01-02 | Switch 2960-24TT ×2 | Fa0/24 de cada um → SW-CORE-01 (Fa0/4/Fa0/5) |
| SW-P02-01 / SW-P02-02 | Switch 2960-24TT ×2 | Fa0/24 de cada um → SW-CORE-01 (Fa0/6/Fa0/7) |
| SW-P03-01 / SW-P03-02 | Switch 2960-24TT ×2 | Fa0/24 de cada um → SW-CORE-01 (Fa0/8/Fa0/9) |
| SRV-INFRA / SRV-PRONT | Server-PT | 10.10.20.21 e 10.10.20.23, gateway 10.10.20.1; ligar DNS/DHCP/HTTP em Services |
| AP-xxx-01 (um por andar) | AccessPoint-PT | cabo na porta do AP (Fa0/1 do SW-xxx-01), SSID LTW-CORP |
| CAM-xxx-01 | PC-PT (representa a câmera) | IP fixo da faixa 10.10.60.x, gateway 10.10.60.1 |
| DT-xxx-01 | PC-PT | DHCP |
| PRN-xxx-01 | Printer-PT | IP fixo 10.x.30.2, gateway 10.x.30.1 |
| NB-VIS | Laptop-PT | liga no SSID LTW-VISITANTES |
| BIO-TER-01 | PC-PT | 10.10.70.11 |

Diferenças deliberadas em relação ao projeto real: o PT não tem PoE nos 2960, não tem LACP no 4331 e não tem controlador UniFi; esses itens estão dimensionados nas planilhas. Os 20 APs, 20 câmeras e 88 pontos completos estão nas plantas e no mapa de portas; o PT reproduz a lógica (VLANs, rotas, DHCP, ACL).

## 2. Cabos (cobre direto = Copper Straight-Through)
1. FW-01 Gi0/0/0 ↔ ISP; FW-01 Gi0/0/1 ↔ SW-CORE-01 Fa0/1.
2. SW-CORE-01 Fa0/2…Fa0/9 ↔ Fa0/24 de SW-TER-01, SW-TER-02, SW-P01-01, SW-P01-02, SW-P02-01, SW-P02-02, SW-P03-01, SW-P03-02 (nessa ordem).
3. SW-CORE-01 Fa0/10 ↔ SRV-INFRA; Fa0/11 ↔ SRV-PRONT.
4. Em cada SW-xxx-01 (PoE): AP na Fa0/1 e câmera na primeira porta de câmera do mapa de portas. Em cada SW-xxx-02: desktop na Fa0/1 e impressora na porta indicada no mapa.

## 3. Configurar (colar o conteúdo, em modo CLI, na ordem)
1. `FW-01.txt` no roteador. 2. `SW-CORE-01.txt`. 3. Os 8 `SW-xxx-nn.txt`. 4. `SRV-INFRA-DHCP.txt`: criar os pools em Services → DHCP (DNS 10.10.20.21). 5. SRV-INFRA: ligar DNS; SRV-PRONT: ligar HTTP/HTTPS.
APs: Config → Port 1 → SSID LTW-CORP, WPA2-PSK (o PT não faz 802.1X). Os SSIDs de VLAN no PT dependem da porta do AP: o AP tagged por SSID não é simulado; para a demonstração, ligue o AP em porta de acesso e documente a diferença.

## 4. Testes (preencher a tabela no `testes/validacao.pdf` com print)
| # | Teste | Resultado esperado |
|---|---|---|
| 1 | PC de cada andar recebe IP por DHCP | IP da faixa da VLAN do andar, gateway .1 |
| 2 | `ping 10.10.20.21` de um desktop | responde |
| 3 | Desktop → `ping 10.10.10.2` (gestão) | bloqueado pela ACL USR-IN |
| 4 | NB-VIS → `ping 10.10.20.21` | bloqueado; `ping 200.10.10.2` responde |
| 5 | CAM → `ping 200.10.10.2` | bloqueado (CFTV sem internet) |
| 6 | DT do posto de segurança do Térreo (10.11.10.2, reserva) → NVR 10.10.60.2 | permitido só desse IP |
| 7 | `tracert` DT-P01 → DT-TER | passa por 10.12.10.1 → 10.11.10.1 |
| 8 | DT → `10.10.20.22` porta 5432 | bloqueado |
| 9 | `show vlan brief` e `show interfaces trunk` nos switches | VLANs e trunks conforme o plano |
| 10 | `show access-lists` no FW-01 após os testes | contadores incrementados nas regras esperadas |

## 5. Entregáveis do Packet Tracer
`topologia.pkt` (feito por você), `topologia-packet-tracer.png` (exportado do PT), `topologia-fisica.png` e `topologia-logica.png` (versão legível, já na pasta), `topologia.drawio` (editável).
