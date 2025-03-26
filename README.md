♥️SSue의 게임 만들기♥️
--------------------------------------
**Environment**

<img src="https://img.shields.io/badge/c++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"> <img src="https://img.shields.io/badge/github-181717?style=for-the-badge&logo=github&logoColor=white">
  <img src="https://img.shields.io/badge/git-F05032?style=for-the-badge&logo=git&logoColor=white">

**Development**

<img src="https://img.shields.io/badge/Raylib-000000?style=for-the-badge&logo=raylib&logoColor=white">

**Communication**

<img src="https://img.shields.io/badge/Notion-000000?style=for-the-badge&logo=notion&logoColor=white"> <img src="https://img.shields.io/badge/Kakaotalk-FFCD00?style=for-the-badge&logo=kakaotalk&logoColor=white"> <img src="https://img.shields.io/badge/Discord-5865F2?style=for-the-badge&logo=discord&logoColor=white"> <img src="https://img.shields.io/badge/Slack-4A154B?style=for-the-badge&logo=slack&logoColor=white">

--------------------------------------
# 🎮 프로젝트 소개
C++과 **Raylib**을 활용해 클래식 **Snake game**과 **Tetris game**을 만들며 게임 로직과 UI 구성 능력을 키우고, 
개발자로서 필수적인 기초 역량을 다지기 위한 **목적**을 갖고 만들었습니다.

--------------------------------------
# 👨‍👩‍👧‍👦 팀 소개
|직분|이름|업무|Git 주소|
|--|--|--|--|
|팀장|김희수|Snake Game구현, 파일 병합, Main화면 디자인|https://github.com/BunnyByee|
|팀원|노수현|Tetris Game구현, README 작성|https://github.com/hhhhhhyun|

---------------------------------------
# 📝프로젝트 기간 및 세부 일정
**2025.03.19 ~ 2025.03.26**
|마일스톤|목표 날짜| 세부 설명
|--|--|--|
|프로젝트 기획|2025.03.19 ~2025.03.29|주제 선정 및 프로젝트 계획서 작성|
|자료 수집|2025.03.20|자료 수집 및 분석 후, 기능 명세서 작성 및 기술 스택 확정|
|1차 기능 구현|2025.03.20 ~2025.03.22|각 기능의 메인 코드 작성 1) Tetris Game 기능, 2) Snake Game 기능|
|1차 기능 통합|2025.03.22 ~2025.03.23|두가지 기능 통합 및 디버깅 작업|
|2차 기능 구현|2025.03.24 ~2025.03.25|기능별 세부 코드 업데이트|
|전체 통합 및 점검|2025.03.25 ~2025.03.26|전체 기능 통합 및 디버깅 후 결과물 확인|
|최종 발표|2025.03.27|프로젝트 발표 시연|

--------
# 🔧주요 기능
**🧱Tetris** 주요 기능
- 블럭 자동 낙하: 일정 시간마다 블럭이 아래로 낙하
- 블럭 회전: ⬆️키 등으로 회전
- 좌우 이동: ⬅️➡️키로 블록 이동
- 하드 드롭: ⬇️로 빠르게 내리기
- 충돌 처리: 바닥이나 블럭에 충돌시 블럭 고정
- 줄 삭제: 가득 찬 줄 제거, 제거 시 위에 있던 블록 전체 아래로 이동
- 점수: 하드 드롭, 줄 삭제 시 점수 증가

**🐍Snake** 주요 기능
- 방향 전환: ⬆️⬅️➡️⬇️키로 뱀 이동 방향 제어
- 뱀 이동: 일정 시간 간격으로 머리가 이동, 몸통은 따라옴
- 먹이 시스템: 먹이를 먹으면 뱀의 길이가 1픽셀 씩 증가
- 충돌 처리: 몸통, 벽에 부딪히면 Game Over
- 먹이 위치: 새로운 먹이는 랜덤한 위치에 생성
- 점수: 먹이를 먹을 시 랜덤한 위치에 생성
  
-------
# ✨화면 구성
|시작 화면|Game Over|
|--|--|
|--|--|
|**Tetris**|**Snake**|
|--|--|

