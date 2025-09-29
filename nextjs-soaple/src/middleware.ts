import {NextRequest, NextResponse} from "next/server";

export function middleware(request: NextRequest) {
  const response = NextResponse.next({
    request: {
      headers: request.headers,
    }
  })

  response.headers.set('x-hello-form-middleware', 'my middleware')

  return response
}