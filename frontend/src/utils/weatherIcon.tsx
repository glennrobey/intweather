import {
  Sun,
  Cloud,
  CloudRain,
  CloudSnow,
  CloudLightning,
  CloudFog,
  Moon,
} from "lucide-react";

export function getWeatherIcon(condition: string) {
  const text = condition.toLowerCase();

  if (text.includes("clear")) {
    return <Sun size={32} className="text-white" strokeWidth={1.5} />;
  }

  if (text.includes("cloud")) {
    return <Cloud size={32} className="text-white" strokeWidth={1.5} />;
  }

  if (text.includes("rain")) {
    return <CloudRain size={32} className="text-white" strokeWidth={1.5} />;
  }

  if (text.includes("snow")) {
    return <CloudSnow size={32} className="text-white" strokeWidth={1.5} />;
  }

  if (text.includes("thunder")) {
    return (
      <CloudLightning size={32} className="text-white" strokeWidth={1.5} />
    );
  }

  if (text.includes("fog")) {
    return <CloudFog size={32} className="text-white" strokeWidth={1.5} />;
  }

  if (text.includes("night")) {
    return <Moon size={32} className="text-white" strokeWidth={1.5} />;
  }

  return <Cloud size={32} className="text-white" strokeWidth={1.5} />;
}
