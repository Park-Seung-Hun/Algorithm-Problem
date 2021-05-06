function solution(nodeinfo) {
    let rootNode
    let preorder = []
    let postorder = []

    /* 노드 값 초기화 */
    const Node = function (x, y, id) {
        this.x = x // 위치
        this.y = y // 높이
        this.id = id
        this.left = null
        this.right = null
    }

    const _insertNode = (node, x, y, id) => {
        const side = x < node.x ? 'left' : 'right'

        if (node[side] === null) {
            /*
                자식 노드가 존재하지 않는 경우 => 노드 생성 (node.x값보다 작은 경우 left , node.x보다 큰 경우 right)
            */
            node[side] = new Node(x, y, id)
        } else {
            /*
                자식 노드가 존재하는 경우 => 자식노드에서 반복
            */
            _insertNode(node[side], x, y, id)
        }
    }

    /* 노드 입력 */
    const insertNode = (x, y, id) => {

        if (!rootNode) { // root노드가 없는 경우 => root노드 생성
            rootNode = new Node(x, y, id)
        } else { // root노드가 있는 경우 => root노드부터 시작해 노드 삽입
            _insertNode(rootNode, x, y, id)
        }
    }

    /* 전위 순회 root -> 좌 -> 우*/
    const _preorder = node => {
        preorder.push(node.id)
        if (node.left) _preorder(node.left)
        if (node.right) _preorder(node.right)
    }

    /* 후위 순회 좌 -> 우 -> root */
    const _postorder = node => {
        if (node.left) _postorder(node.left)
        if (node.right) _postorder(node.right)
        postorder.push(node.id)
    }

    /* 노드 값 정리 [x,y,idx] 후 y 값에 대해 내림차순 정렬 */
    const nodes = nodeinfo.map(([x, y], idx) => [x, y, idx+1]);
    nodes.sort(([, ya], [, yb]) => yb - ya)

    /* 정리된 노드 값을 이진 트리로 만들기 */
    nodes.forEach(([x, y, id]) => insertNode(x, y, id))

    _preorder(rootNode)
    _postorder(rootNode)

    return [preorder, postorder]
}
