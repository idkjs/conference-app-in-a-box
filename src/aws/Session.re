open Utils;
[@bs.deriving abstract]
type t = {
  mutable complexObjectCredentials: string,
  mutable jwtToken: string,
  mutable username: string,
  mutable email: string,
};

let session =
  t(~complexObjectCredentials="", ~jwtToken="", ~username="", ~email="");

let getToken = () => session->jwtTokenGet;
let getUser = () => session->usernameGet;
let getEmail = () => session->emailGet;
let getComplex = () => session->complexObjectCredentialsGet;

let setToken = v => {
  session->jwtTokenSet(v);
  ReactNative.AsyncStorage.setItem(namespace ++ "token", v);
};
let setUser = v => {
  session->usernameSet(v);
  ReactNative.AsyncStorage.setItem(namespace ++ "username", v);
};
let setEmail = v => {
  session->emailSet(v);
  ReactNative.AsyncStorage.setItem(namespace ++ "email", v);
};
let setComplex = v => {
  session->complexObjectCredentialsSet(v);
  ReactNative.AsyncStorage.setItem(namespace ++ "complex", v);
};

// Js.Promise.(
//   Auth.currentUserCredentials()
//   |> then_(result => {
//        //  Js.log2("complexObjectsCredentials_SESSION: ", result);
//        setComplex(result) |> ignore;
//        //  Js.log2("SESSION_GET_COMPLEX: ", getComplex());
//        //  Js.log2("SESSION_ALL: ", session);
//        resolve();
//      })
// );

let setSession =
  PromiseMonad.(
    Auth.getCurrentAuthUser()
    >>= (
      response => {
        Belt.Option.(
          response
          |> (
            r => {
              // Js.log2("SESSION_RESPONSE", r);
              let jwtToken =
                r##signInUserSession
                ->flatMap(session => session##accessToken)
                ->flatMap(accessToken => accessToken##jwtToken)
                ->getWithDefault("");
              let userSession =
                r##signInUserSession->Js.Json.stringifyAny->getExn;

              setToken(jwtToken) |> ignore;
              let username = r##username->getWithDefault("");
              Js.log2("SESSION_USERNAME:", username);
              setUser(username) |> ignore;
              let email =
                r##signInUserSession
                ->flatMap(session => session##idToken)
                ->flatMap(idToken => idToken##payload)
                ->flatMap(payload => payload##email)
                ->getWithDefault("");
              Js.log2("SESSION_email:", email);
              setEmail(email) |> ignore;
              setComplex(userSession) |> ignore;
              return(session);
            }
          )
        );
      }
    )
  );
