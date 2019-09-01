/* Import Hub as Hub, type as Hub */
// type hub;
// [@bs.module ("aws-amplify", "Hub")] external hub: hub = "Hub";
// type hubPayload = {
//   event: string,
//   data: option(Js.t({.})),
//   message: option(string),
// };
// type hubCapsule = {
//   channel: string,
//   payload: hubPayload,
//   source: string,
//   patternInfo: option(array(string)),
// };
// type hubCallback;
// [@bs.module ("@aws-amplify/core", "HubCallback")]
// external hubCallback: (hubCapsule, unit) => hubCallback = "HubCallback";
/* Build a function that will call the `listen` method of an object passed
   as the first argument. */
// type listener = {

// };
// type payload;
// [@bs.send] external listen: (hub, unit) => Js.Promise.t(hubCallback) => listen = "listen";

// [@bs.send] external listen: t('a, 'e) => unit = "listen";
// [@bs.send] external listen: (hub,string) => unit = "listen";
// let listen = string => listen(hub,string);
// [@bs.send] external remove: hub => unit = "remove";
// let remove = remove(hub);
// type logger;
// [@bs.new] [@bs.module ("aws-amplify", "Logger")]
// external logger: unit => logger = "Logger";


type t = string;

[@bs.inline]
let active = "active";

[@bs.inline]
let background = "background";

[@bs.inline]
let inactive = "inactive";

// [@bs.inline "background"]
// let background: t;

// [@bs.inline "inactive"]
// let inactive: t;

// [@bs.scope "Hub"] [@bs.module "aws-amplify"]
// external currentState: t = "";

[@bs.scope "Hub"] [@bs.module "aws-amplify"]
external listen:
  (
  [@bs.string]
  [
    | `change(t => unit)
  ]
  ) =>
  unit =
  "listen";

[@bs.scope "Hub"] [@bs.module "aws-amplify"]
external remove:
  (
  [@bs.string]
  [
    | `change(t => unit)
  ]
  ) =>
  unit =
  "remove";
