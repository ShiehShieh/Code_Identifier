

program promessage;
const
  infinity = 134744072;
  maxm = 100;
  maxn = 100;
  maxv = maxm * maxn * 2;
  maxe = maxv * 2;
type
  tindex = longint;
  tdata = longint;
  tedge = record
    start, ending : tindex;
    capa, cost, flow : tdata;
    prev : tindex;
  end;
var
  m, n, totalcost, totalflow, v, e : tdata;
  i, j, source, sink, push, pop : tindex;
  queue : array [0..maxv * 16 + 1] of tindex;
  bein : array [0..maxv + 1] of boolean;
  pre, last : array [0..maxv + 1] of tindex;
  dist : array [0..maxv + 1] of tdata;
  map : array [0..maxm + 1, 0..maxn + 1] of tindex;
  w : array [0..maxm + 1, 0..maxn + 1] of tdata;
  edge : array [-maxe - 1..maxe + 1] of tedge;

  procedure buildgraph;

    procedure addedge(const fnum, fstart, fending : tindex;const fcapa, fcost : tdata);
    begin
      with edge[fnum] do
      begin
        start := fstart;
        ending := fending;
        capa := fcapa;
        cost := fcost;
        flow := 0;
        prev := last[fstart];
        last[fstart] := fnum;
      end;
      with edge[-fnum] do
      begin
        start := fending;
        ending := fstart;
        capa := 0;
        cost := -fcost;
        prev := last[fending];
        last[fending] := -fnum;
      end;
    end;

  begin
    v := 0;
    source := 1;
    readln(m, n);
    for i := 1 to m do
      for j := 1 to n do
      begin
        read(w[i, j]);
        inc(v);
        map[i, j] := v;
      end;
    fillchar(last, sizeof(last), 0);
    e := 0;
    inc(e);
    addedge(e, 1, 2, 2, w[1, 1]);
    
    for i := 1 to m do
      for j := 1 to n do
        if not((i = 1)and(j = 1)) then
        begin
          if i > 1 then
          begin
            inc(e);
            addedge(e, map[i - 1, j] * 2, map[i, j] * 2 - 1, 1, 0);
          end;
          if j > 1 then
          begin
            inc(e);
            addedge(e, map[i, j - 1] * 2, map[i, j] * 2 - 1, 1, 0);
          end;

          inc(e);
          addedge(e, map[i, j] * 2 - 1, map[i, j] * 2, 1 + ord((i = m)and(j = n)), w[i, j]);
        end;
    sink := v * 2;
  end;

  function spfa : boolean;
  var
    cur, ptr : tindex;
  begin
    fillchar(pre, sizeof(pre), 0);
    fillchar(queue, sizeof(queue), 0);
    fillchar(bein, sizeof(bein), false);
    push := 1;
    pop := 2;
    queue[push] := source;
    fillchar(dist, sizeof(dist), 255);
    dist[source] := 0;

    while push < pop do
    begin
      cur := queue[push];

      ptr := last[cur];
      while ptr <> 0 do
        with edge[ptr] do
        begin
          if (flow < capa)and(dist[cur] + cost > dist[ending]) then
          begin
            dist[ending] := dist[cur] + cost;
            pre[ending] := ptr;
            if not bein[ending] then
            begin
              queue[pop] := ending;
              inc(pop);
              bein[ending] := true;
            end;
          end;
          ptr := prev;
        end;

      inc(push);
      bein[cur] := false;
    end;

    spfa := (dist[sink] > -1);
  end;

  procedure adjust;
  var
    ptr : tindex;
  begin
    inc(totalflow);
    inc(totalcost, dist[sink]);
    ptr := pre[sink];
    while ptr <> 0 do
      with edge[ptr] do
      begin
        inc(flow);
        dec(edge[-ptr].flow);
        ptr := pre[start];
      end;
  end;

  procedure mincost;
  begin
    totalflow := 0;
    totalcost := 0;
    while spfa do
      adjust;
  end;

  procedure main;
  begin
    buildgraph;
    mincost;
    write(totalcost);
  end;

begin
  main;
end.
