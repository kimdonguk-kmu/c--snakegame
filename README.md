# c--snakegame

<h1>SnakeGame</h1>
<h2> 프로젝트 소개</h2>   

  + 이 프로젝트는 국민대학교 소프트웨어학부에서 c++ 프로그래밍 강의의 팀 프로젝트로 ncurses.h 라이브러리를 이용하여 c++ 언어로 snake game을 구현하고자 한다.

<h2> snake game의 소개</h2>

  + snake game은 화면에 있는 snake를 움직여 화면의 장애물에 접촉하지 않고 growth item과 poison item을 얻으며 진행하는 게임이다.

<h2> 개발 환경 </h2>

  + 본 프로젝트는 국민대학교 소프트웨어학과에서 표준 환경으로 요구하는 linux Ubuntu 20.04(Ubuntu)를 기준으로 개발하였으며, c++ 소스 코드 컴파일을 위해 GCC/g++을 사용하고 있다.

<h2> 게임 규칙 </h2>

**방향키**를 이용하여 snake를 상하좌우로 움직인다. 방향키를 입력하지 않으면 마지막으로 입력하였던 방향으로 계속 움직인다.

  + **wall(벽)**에 부딪히면 snake는 그 즉시 죽으며 게임이 종료된다.
  + 2가지 아이템으로 몸의 길이를 늘리거나 줄일 수 있다.
  + level은 총 4단계로 이루어져있으며, 각 level에는 그에 상응하는 mission이 있다.
  + snake를 움직이며 미션을 완료하면 그 level을 클리어 할 수 있다.
  + 이하는 상세한 규칙이다.

<h3> 아이템 </h3>

snake game에는 2가지의 item이 존재한다

```
Growth item -> snake의 head와 겹치면 몸의 길이가 1만큼 증가한다.
Poison item -> snake의 head와 겹치면 몸의 길이가 1만큼 감소한다.
```  

  + **item**은 별도의 object(ex: wall(벽), snake(뱀)) 등 무언가가 존재하지 않는 곳에 겹치지 않게 2개가 한꺼번에 생성되며, 한 번 생성될 때 각각 한 개씩 등장한다.
  + **item**은 출현 후 일정 시간이 지나면 사라지며, 그 즉시 다른 위치에 나타나게 된다.
  + **item**은 동시에 3개 이하만 출현할 수 있다. 

<h3> 게이트 </h3>

  + **gate(게이트)** 는 2개가 한 쌍으로 나타나며 서로 겹치지 않는다.
  + **gate**에 진입하면 하면 다른 **gate**로 나오게 된다.
  + **gate**는 일정 시간이 지나면 존재하던 게이트는 사라지며 다른 한 쌍의 게이트가 생성된다. 하지만 snake가 통과중일 때는 일정 시간이 지나더라도 삭제되지 않는다.
  + **gate**은 일반 wall애는 나타나지만 immune wall에는 나타나지 않는다.

<h3> 스코어보드, 미션 </h3>

```
**scoreboard**는 현재 snake game의 현황을 나타낸다.
**scoreboard**는 snake의 몸길이, 먹은 item, 통과한 gate, level, time이 출력된다.
**scoreboard**는 출력된 현황의 내용이 바뀌면 실시간으로 조정된다.
**scoreboard**는 다음 level로 이동하게 되면 초기화된다.
```
```
**mission**은 다음 level로 이동하기 위해 달성해야 하는 조건이다.
**mission**은 snake의 몸 길이, 먹은 item들의 수, 통과한 gate의 수로 이루어져 있다.
**mission**을 모두 달성하면 그 즉시 다음 level로 이동한다.
**mission**은 level마다 다르게 설정되어있다.
```

<h3> 승리 조건 </h3>
  + 모든 미션을 달성한 채 level 4를 클리어하면 승리한다.

<h3> 패배 조건 </h3>
  + wall이나 immune wall에 부딪히면 그 즉시 패배한다.
  + snake의 몸 길이가 3 이하이면 패배한다.
  + snake가 자신의 몸통에 부딛히면 패배한다. 자신의 진행방향의 반대로 이동하는 것도 몸통에 부딪히는 것으로 판단한다.

<h2> 시연 영상 </h2>
https://www.youtube.com/watch?v=Rygt4xVik3Q

<h2> 작성자 </h2>

'''
  + 이름: 김동욱
  + 학번: 20212963
'''

<h2> 설치 방법 </h2>

<h3> 1. git clone </h3>
1.1 게임을 설치하고자 하는 디렉토리로 이동한다

1.2 git clone https://github.com/kimdonguk-kmu/c--snakegame
을 입력한다.

<h3> 2. make run </h3>
1.1 설치한 디렉토리로 이동한다.

1.2 make run을 입력한다.

<h3> 게임 실행 </h3>
1.1 ./game을 터미널에 입력하여 게임을 실행한다.
