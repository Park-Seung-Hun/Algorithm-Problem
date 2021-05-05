function solution(board) {
    const N = board.length
    // 우 하 좌 상
    const direction = [[1, 0], [0, -1], [-1, 0], [0, 1]];

    // x, y, 방향인덱스(초기 null), cost
    const q = [[0, 0, null, 0]];

    while (q.length) {
        const [x, y, dir, cost] = q.shift();

        // board가 방문한적 + 벽이고 비용보다 작은 경우
        if (board[x][y] < cost && board[x][y] > 0) continue;
        board[x][y] = cost;

        direction.forEach(([i, j], ndir) => {

            // 시작지점이 아니고 방향이 반대인 곳은 가지 않는다.
            if (dir !== null && Math.abs(ndir - dir) === 2) return;

            const [nx, ny] = [x + i, y + j];

            // nx,ny가 범위를 벗어나거나, 벽에 막힐 경우
            if (0 > nx || nx >= N || 0 > ny || ny >= N || board[nx][ny] === 1) return;

            // ndir은 0(우),1(아래),2(좌),3(위)
            // dir이 처음이 아니고 방향이 달라지면 +600 , 처음이거나 방향이 같으면 +100
            q.push([nx, ny, ndir, dir !== null && dir !== ndir ? cost + 600 : cost + 100]);
        })
    }
    return board[N - 1][N - 1];
}
