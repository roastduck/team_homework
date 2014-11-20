uses math;
var
   n,i,tt,tp,j,k:longint;
   now:extended;
   a:array[0..50000]of record t,p:longint;res:double end;
   ans:array[0..50000]of longint;
procedure qsort2(i,j:longint);
var
   q,p:longint;
   mid:double;
begin
   q:=i;
   p:=j;
   mid:=a[(i+j)shr 1].res;
   repeat
      while a[q].res<mid do inc(q);
      while a[p].res>mid do dec(p);
      if q<=p then begin
         a[0]:=a[q];
         a[q]:=a[p];
         a[p]:=a[0];
         inc(q);
         dec(p);
      end;
   until q>p;
   if i<p then qsort2(i,p);
   if q<j then qsort2(q,j);
end;
begin
   assign(input,'school.in'); reset(input);
   assign(output,'school.ans'); rewrite(output);
   readln(n);
   for i:=1 to n do begin
      readln(a[i].t,a[i].p);
      a[i].res:=a[i].t/a[i].p;
      inc(tt,a[i].t);
      inc(tp,a[i].p);
   end;
   qsort2(1,n);
   for i:=1 to n-1 do begin
      dec(tt,a[i].t);
      dec(tp,a[i].p);
      now:=1e10;
      for j:=1 to i do now:=min(now,a[j].p/tp-a[j].t/tt);
      for j:=i+1 to n do if a[j].p/tp-a[j].t/tt{int64(tt)*a[j].p-int64(tp)*a[j].t}>now then begin
         inc(ans[0]);
         ans[ans[0]]:=i;
         break;
      end;
   end;
   writeln(ans[0]);
   for i:=1 to ans[0] do writeln(ans[i]);
end.

