var
   n,m,i,j,nd,nr,mi,k:longint;
   a:array[1..18]of longint;
   ans:array[0..18]of longint;
   f:array[0..524288]of record d,r:longint;end;
function log2(x:longint):longint;
begin
   exit(round(ln(x)/ln(2)));
end;
begin
   readln(n,m);
   mi:=(1 shl n)-1;
   for i:=1 to n do readln(a[i]);
   for i:=1 to mi do
      f[i].d:=maxlongint;
   f[0].d:=-1;
   f[0].r:=m;
   for i:=1 to mi do
      for j:=0 to n-1 do if i and (1 shl j)>0 then with f[i xor (1 shl j)] do begin
         if r+a[j+1]<=m then begin
            nr:=r+a[j+1];
            nd:=d;
         end else begin
            nr:=a[j+1];
            nd:=d+1;
         end;
         if (nd<f[i].d) or ((nd=f[i].d) and (nr<f[i].r)) then begin
            f[i].d:=nd;
            f[i].r:=nr;
         end;
      end;
   writeln(f[mi].d+longint(f[mi].r>0));
end.

