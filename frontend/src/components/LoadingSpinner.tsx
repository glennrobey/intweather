import { CloudSun } from "lucide-react";

function LoadingSpinner() {
  return (
    <div className="flex flex-col items-center gap-3 text-white">
      <CloudSun size={45} className="animate-pulse" strokeWidth={1.5} />

      <p className="text-lg">Checking the skies...</p>
    </div>
  );
}

export default LoadingSpinner;
