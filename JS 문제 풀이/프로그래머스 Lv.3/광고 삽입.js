function solution(play_time, adv_time, logs) {
  var answer = "";

    /* 전체 구간에서 특정 길이만큼 구간합이 가장 큰 구간을 구하는 문제 */

    /* 재생시간 = 광고시간 => 00:00:00부터 */
    if (play_time === adv_time) return "00:00:00";

    /* 문자열=> 초*/
    const getSec = (str) => {
        const t = str.split(":");
        return parseInt(t[0]) * 3600 + parseInt(t[1]) * 60 + parseInt(t[2]);
    };

    /* 초 => 문자열 */
    const getStr = (sec) => {
        const h = parseInt(sec / 3600);
        sec %= 3600;
        const m = parseInt(sec / 60);
        const s = sec % 60;

        return (
          (h < 10 ? `0${h}` : `${h}`) +
          ":" +
          (m < 10 ? `0${m}` : `${m}`) +
          ":" +
          (s < 10 ? `0${s}` : `${s}`)
        );
    };

    /* 재생시간과 광고시간을 초로 변환 */
    const playTime = getSec(play_time);
    const advTime = getSec(adv_time);

    const viewer = Array.from({ length: playTime + 1 }, () => 0); // 시청자 수

    /* 기록들 전부 변환 => 시작,끝 */
  logs.forEach((log) => {
    log = log.split("-");
    const start = getSec(log[0]);
    const end = getSec(log[1]);

      /* 시작시간엔 시청자수 증가 , 종료시간엔 시청자수 감소 */
    viewer[start]++;
    viewer[end]--;
  });

  for (let i = 1; i <= playTime; i++) viewer[i] += viewer[i - 1]; // 시청자 수 갱신

  let curTime = 0; // 누적 재생 시간
    /* 00:00:00부터 광고시간까지 시청자 시청 시간 */
  for (let i = 0; i < advTime; i++) curTime += viewer[i];

  let startTime = 0;
  let maxTime = curTime;

  for (let i = advTime; i < playTime; i++) {
    curTime += viewer[i]; // 종료시간 1초씩 증가하면서
    curTime -= viewer[i - advTime]; // 시작시간 1초씩 증가하면서

    if (curTime > maxTime) {
      maxTime = curTime;
      startTime = i - advTime + 1;
    }
  }
  answer = getStr(startTime); // 변환

  return answer;
}
